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

Zombie::Zombie(const XMFLOAT3& position)
{
	GetTransform()->Translate(position);
}

void Zombie::Initialize(const SceneContext&)
{
	const auto pSkinnedMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Skinned>();
	pSkinnedMaterial->SetDiffuseTexture(L"Textures/Mobs/Zombie.png");

	const auto pModel = AddComponent(new ModelComponent(L"Meshes/Mobs/Zombie.ovm"));
	pModel->SetMaterial(pSkinnedMaterial);

	const auto pMaterial = PxGetPhysics().createMaterial(.5f, .5f, .5f);

	m_pRigidBody = AddComponent(new RigidBodyComponent{ false });
	m_pRigidBody->AddCollider(PxBoxGeometry{ 0.5f,1.f,0.5f }, *pMaterial, false, PxTransform{{0,1.f,0}});

	m_pAnimator = pModel->GetAnimator();
	m_pAnimator->SetAnimation(m_animationClipId);
	m_pAnimator->Play();
}

void Zombie::Update(const SceneContext& sceneContext)
{
	const auto& playerPosition = sceneContext.pCamera->GetTransform()->GetWorldPosition();
	const auto& position = GetTransform()->GetWorldPosition();

	const XMVECTOR vector = XMLoadFloat3(&playerPosition) - XMLoadFloat3(&position);
	const float distance = XMVectorGetX(XMVector3Length(vector));

	constexpr float range { 10.f };

	if (distance >= range) //Idle state
	{
		m_animationClipId = 0;
	}
	else //Player in range
	{
		m_animationClipId = 1;
		
	}

	UpdateAnimation();
}
