#include "stdafx.h"
#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(const std::wstring& spriteAsset, const XMFLOAT2& pivot, const XMFLOAT4& color) :
	m_SpriteAsset(spriteAsset),
	m_Pivot(pivot),
	m_Color(color)
{
	m_enablePostDraw = true;
}

const XMFLOAT2& SpriteComponent::GetSize() const
{
	return m_pTexture->GetDimension();
}

void SpriteComponent::Initialize(const SceneContext& /*sceneContext*/)
{
	m_pTexture = ContentManager::Load<TextureData>(m_SpriteAsset);
}

void SpriteComponent::SetTexture(const std::wstring& spriteAsset)
{
	m_SpriteAsset = spriteAsset;
	m_pTexture = ContentManager::Load<TextureData>(m_SpriteAsset);
}

void SpriteComponent::SetDimensions(const XMFLOAT2& dimensions)
{
	if (!m_pTexture)
	{
		m_pTexture = ContentManager::Load<TextureData>(m_SpriteAsset);
	}
	const auto originalWidth = m_pTexture->GetDimension().x;
	const auto originalHeight = m_pTexture->GetDimension().y;
	const auto widthScale = dimensions.x / originalWidth;
	const auto heightScale = dimensions.y / originalHeight;
	GetTransform()->Scale(XMFLOAT3{ widthScale,heightScale,1.f });
}

void SpriteComponent::PostDraw(const SceneContext&)
{
	if (!m_pTexture)
		return;

	TransformComponent* pTransform{ GetGameObject()->GetComponent<TransformComponent>() };
	const XMFLOAT3& position{ pTransform->GetWorldPosition() };
	const XMFLOAT3& scale{ pTransform->GetWorldScale() };

	SpriteRenderer::Get()->AppendSprite(
		m_pTexture,
		XMFLOAT2{ position.x, position.y }, m_Color,
		m_Pivot, XMFLOAT2{ scale.x, scale.y },
		MathHelper::QuaternionToEuler(pTransform->GetWorldRotation()).z,
		position.z);
}
