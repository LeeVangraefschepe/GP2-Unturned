#include "stdafx.h"
#include "Zombie.h"
#include <Materials/DiffuseMaterial_Skinned.h>

void Zombie::UpdateAnimation()
{
	if (m_animationClipId != m_lastAnimationClipId)
	{
		std::cout << "Animation set on: " << m_animationClipId << "\n";
		m_pAnimator->SetAnimation(m_animationClipId);
		m_lastAnimationClipId = m_animationClipId;
	}
}

void Zombie::UpdateMovement(const XMVECTOR& direction, const XMFLOAT3& playerPosition, float deltaTime)
{
	constexpr float movementSpeed{ 6.f };

	const XMVECTOR walkingDirection = XMVectorScale(direction, movementSpeed);

	//Get direction to XMFLOAT3
	XMFLOAT3 velocity{};
	XMStoreFloat3(&velocity, walkingDirection);

	m_totalVelocity = velocity;
	m_totalVelocity.x *= deltaTime;
	m_totalVelocity.y *= deltaTime;
	m_totalVelocity.z *= deltaTime;

	if (!(m_pControllerComponent->GetCollisionFlags() & PxControllerCollisionFlag::eCOLLISION_DOWN))
	{
		m_totalVelocity.y -= m_fallAcceleration * deltaTime;
		m_totalVelocity.y = std::max(m_totalVelocity.y, -10.f);
	}
	else
	{
		m_totalVelocity.y = -0.1f;
	}

	m_pControllerComponent->Move(m_totalVelocity);

	const XMFLOAT3 lookAtDirection = GetTransform()->LookAtDirection(playerPosition);

	//Apply movement
	GetTransform()->Rotate(lookAtDirection, false);
}

void Zombie::UpdateAttack(float distance, const XMFLOAT3&)
{
	constexpr float attackRange{ 2.f };
	if (distance > attackRange) { return; }
	if (m_currentAttackDelay > 0.f) { return; }

	m_currentAttackDelay = m_attackDelay;
	m_playerHealth->Damage(m_damage);
}

void Zombie::OnNotify(unsigned event, Health*)
{
	if (static_cast<Health::Events>(event) == Health::died)
	{
		GetTransform()->Translate(XMFLOAT3{ 0,-100,0 });
		m_pControllerComponent->Translate(XMFLOAT3{ 0,-100,0 });
		SetActive(false);
	}
}

Zombie::Zombie(const XMFLOAT3& position, GameObject* target)
{
	GetTransform()->Translate(position);
	m_playerHealth = target->GetComponent<Health>();
}

void Zombie::Initialize(const SceneContext&)
{
	m_pVisuals = new GameObject{};
	AddChild(m_pVisuals);
	const auto pSkinnedMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Skinned>();
	pSkinnedMaterial->SetDiffuseTexture(L"Textures/Mobs/Zombie.dds");

	const auto pModel = m_pVisuals->AddComponent(new ModelComponent(L"Meshes/Mobs/Zombie.ovm"));
	pModel->SetMaterial(pSkinnedMaterial);

	m_pVisuals->GetTransform()->Translate(0, -1, 0);

	const auto pMaterial = PxGetPhysics().createMaterial(.5f, .5f, .5f);
	
	m_pAnimator = pModel->GetAnimator();
	m_pAnimator->SetAnimation(m_animationClipId);
	m_pAnimator->Play();

	auto controller = PxCapsuleControllerDesc{};
	controller.setToDefault();
	controller.radius = 0.75f;
	controller.height = 2.f;
	controller.material = pMaterial;
	m_pControllerComponent = new ControllerComponent{ controller };
	m_pControllerComponent->SetCollisionGroup(CollisionGroup::Group5);
	AddComponent(m_pControllerComponent);

	AddComponent(new Health{ 1.f })->GetSubject()->AddObserver(this);
}

void Zombie::Update(const SceneContext& sceneContext)
{
	const float deltaTime = sceneContext.pGameTime->GetElapsed();
	m_currentAttackDelay -= deltaTime;

	auto playerPosition = sceneContext.pCamera->GetTransform()->GetWorldPosition();
	const auto& position = GetTransform()->GetWorldPosition();
	playerPosition.y = position.y;
	
	XMVECTOR vector = XMLoadFloat3(&playerPosition) - XMLoadFloat3(&position);
	const float distance = XMVectorGetX(XMVector3Length(vector));
	
	//Normalize direction
	vector = XMVector3Normalize(vector);
	
	constexpr float range { 20.f };
	
	if (distance >= range) //Idle state
	{
		m_animationClipId = 0;
	}
	else //Player in range
	{
		m_animationClipId = 1;
		UpdateMovement(vector, playerPosition, deltaTime);
		UpdateAttack(distance, playerPosition);
	}
	
	UpdateAnimation();
}
