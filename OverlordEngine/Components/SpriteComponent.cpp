#include "stdafx.h"
#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(const std::wstring& spriteAsset, const XMFLOAT2& pivot, const XMFLOAT4& color):
	m_SpriteAsset(spriteAsset),
	m_Pivot(pivot),
	m_Color(color)
{}

void SpriteComponent::Initialize(const SceneContext& /*sceneContext*/)
{
	m_pTexture = ContentManager::Load<TextureData>(m_SpriteAsset);
}

void SpriteComponent::SetTexture(const std::wstring& spriteAsset)
{
	m_SpriteAsset = spriteAsset;
	m_pTexture = ContentManager::Load<TextureData>(m_SpriteAsset);
}

void SpriteComponent::SetDepth(float depth)
{
	m_depth = depth;
}

void SpriteComponent::SetDimensions(float width, float height)
{
	if (!m_pTexture)
	{
		m_pTexture = ContentManager::Load<TextureData>(m_SpriteAsset);
	}
	const auto originalWidth = m_pTexture->GetDimension().x;
	const auto originalHeight = m_pTexture->GetDimension().y;
	const auto widthScale = width / originalWidth;
	const auto heightScale = height / originalHeight;
	GetTransform()->Scale(XMFLOAT3{ widthScale,heightScale,1.f});
}

void SpriteComponent::Draw(const SceneContext&)
{
	if (!m_pTexture)
		return;

	const TransformComponent* pTransform{ GetGameObject()->GetComponent<TransformComponent>() };
	const XMFLOAT3& position{ pTransform->GetWorldPosition() };
	const XMFLOAT3& scale{ pTransform->GetWorldScale() };

	float depth;
	if (m_depth < 0)
	{
		depth = position.z;
	}
	else
	{
		depth = m_depth;
	}

	SpriteRenderer::Get()->AppendSprite
	(
		m_pTexture,
		XMFLOAT2{ position.x, position.y },
		m_Color,
		m_Pivot,
		XMFLOAT2{ scale.x, scale.y },
		MathHelper::QuaternionToEuler(pTransform->GetWorldRotation()).z,
		depth
	);

	//Here you need to draw the SpriteComponent using the Draw of the sprite renderer
	// The sprite renderer is a singleton
	// you will need to position (X&Y should be in screenspace, Z contains the depth between [0,1]), the rotation and the scale from the owning GameObject
	// You can use the MathHelper::QuaternionToEuler function to help you with the z rotation 
}
