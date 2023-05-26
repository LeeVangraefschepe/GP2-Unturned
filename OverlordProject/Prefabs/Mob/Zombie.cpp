#include "stdafx.h"
#include "Zombie.h"
#include <Materials/DiffuseMaterial_Skinned.h>
#include <Materials/DiffuseMaterial.h>

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
	constexpr float movementSpeed{ 0.1f };

	const XMVECTOR walkingDirection = XMVectorScale(direction, movementSpeed);

	//Get direction to XMFLOAT3
	XMFLOAT3 velocity{};
	XMStoreFloat3(&velocity, walkingDirection);

	m_totalVelocity = velocity;
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

Zombie::Zombie(const XMFLOAT3& position)
{
	GetTransform()->Translate(position);
}

void Zombie::Initialize(const SceneContext&)
{
	m_pVisuals = new GameObject{};
	AddChild(m_pVisuals);
	const auto pSkinnedMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Skinned>();
	pSkinnedMaterial->SetDiffuseTexture(L"Textures/Mobs/Zombie.png");

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
	AddComponent(m_pControllerComponent);
}

void Zombie::Update(const SceneContext& sceneContext)
{
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
		UpdateMovement(vector, playerPosition, sceneContext.pGameTime->GetElapsed());
	}
	
	UpdateAnimation();
}
