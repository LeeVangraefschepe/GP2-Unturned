#include "stdafx.h"
#include "WeaponUse.h"

bool WeaponUse::OnHit(Health*& pHealth, XMFLOAT3& position)
{
	const auto rayOrigin = PhysxHelper::ToPxVec3(GetTransform()->GetWorldPosition());
	const auto rayDirection = PhysxHelper::ToPxVec3(GetTransform()->GetForward());

	std::cout << "Try\n";

	//Filter for ignore groups
	PxQueryFilterData filterData{};
	filterData.data.word0 = ~static_cast<UINT>(CollisionGroup::Group9);

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

	switch (const Item usedItem = m_pWeaponSlot->GetSelectedItem())
	{
	case pistol:
		{
			
			if (OnHit(otherHealth, position))
			{
				std::cout << "Hit: "<< position.x << ", " << position.y << ", " << position.z << "\n";
				if (otherHealth)
				{
					if (otherHealth->Damage(1.f))
					{

					}
					std::cout << "Hit with health\n";
				}
			}
		}
		break;

	case all:
	default:
		break;
	}
}