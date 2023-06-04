#include "stdafx.h"
#include "WeaponUse.h"

#include "Food.h"
#include "ScoreManager.h"

void WeaponUse::PlayFireSound()
{
	const auto pFmod{ SoundManager::Get()->GetSystem() };
	const FMOD_RESULT result{ pFmod->playSound(m_fireSound, nullptr, false, &m_channel) };
	SoundManager::Get()->ErrorCheck(result);

	//Range sound
	m_channel->set3DMinMaxDistance(0.f, 15.f);

	//Apply settings
	const auto spherePos = FmodHelper::ToFmod(GetTransform()->GetWorldPosition());
	const auto sphereVel = FmodHelper::ToFmod(XMFLOAT3{ 0,0,0 });
	m_channel->set3DAttributes(&spherePos, &sphereVel);
}

bool WeaponUse::OnHit(Health*& pHealth, XMFLOAT3& position)
{
	const auto rayOrigin = PhysxHelper::ToPxVec3(GetTransform()->GetWorldPosition());
	const auto rayDirection = PhysxHelper::ToPxVec3(GetScene()->GetActiveCamera()->GetTransform()->GetForward());

	//Filter for ignore groups
	PxQueryFilterData filterData{};
	filterData.data.word0 = ~static_cast<UINT>(CollisionGroup::Group9);

	PlayFireSound();

	//Raycast
	if (PxRaycastBuffer hit{}; GetScene()->GetPhysxProxy()->Raycast(rayOrigin, rayDirection.getNormalized(), 100.f, hit, PxHitFlag::eDEFAULT, filterData))
	{
		// Check if there is a touch result
		if (hit.hasBlock)
		{
			const auto gameobject = static_cast<BaseComponent*>(hit.block.actor->userData)->GetGameObject();
			pHealth = gameobject->GetComponent<Health>();

			const auto& pxPos = hit.block.position;

			position = XMFLOAT3{ pxPos.x, pxPos.y, pxPos.z };
			return true;
		}
	}

	return false;	
}

WeaponUse::WeaponUse(WeaponSlot* weaponSlot) :
	m_pWeaponSlot(weaponSlot)
{
	m_pWeaponSlot->GetSubject()->AddObserver(this);

	const auto pFmod{ SoundManager::Get()->GetSystem() };
	std::stringstream filePath{};
	filePath << "Resources/Audio/Fire.mp3";
	const FMOD_RESULT result = pFmod->createStream(filePath.str().c_str(), FMOD_3D | FMOD_3D_LINEARROLLOFF, nullptr, &m_fireSound);
	SoundManager::Get()->ErrorCheck(result);
}

WeaponUse::~WeaponUse()
{
	if (m_pWeaponSlot)
	{
		m_pWeaponSlot->GetSubject()->RemoveObserver(this);
	}
}

void WeaponUse::OnDestroy()
{
	m_pWeaponSlot = nullptr;
}

void WeaponUse::OnNotify(unsigned event, WeaponSlot*)
{
	if (static_cast<WeaponSlot::Events>(event) != WeaponSlot::Use) { return; }

	XMFLOAT3 position{};
	Health* otherHealth{};

	ScoreManager::Get()->AddScore(10);

	switch (const Item usedItem = m_pWeaponSlot->GetSelectedItem())
	{
	case pistol:
		{
			
			if (OnHit(otherHealth, position))
			{
				std::cout << "Hit: "<< position.x << ", " << position.y << ", " << position.z << "\n";
				m_pHitParticle->SetParticle(position);
				if (otherHealth)
				{
					if (otherHealth->Damage(1.f))
					{
						ScoreManager::Get()->AddScore(50);
						std::cout << "Zombie died\n";
					}
					std::cout << "Hit with health\n";
				}
			}
		}
		break;
	case food:
		GetGameObject()->GetComponent<Food>()->Eat(20.f);
		break;
	case all:
	default:
		break;
	}
}

void WeaponUse::Initialize(const SceneContext&)
{
	m_pHitParticle = new HitParticle{};
	m_pHitParticle->SetActive(false);
	GetScene()->AddChild(m_pHitParticle);
}
