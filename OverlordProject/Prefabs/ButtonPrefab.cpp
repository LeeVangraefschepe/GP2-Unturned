#include "stdafx.h"
#include "ButtonPrefab.h"

ButtonPrefab::ButtonPrefab(const std::wstring& texture, XMFLOAT2 dimensions)
{
	m_pSpriteComp = AddComponent(new SpriteComponent(texture, { 0.f,0.f }, { 1.f,1.f,1.f,1.f }));
	m_pSpriteComp->SetDimensions(dimensions.x, dimensions.y);
}

void ButtonPrefab::Initialize(const SceneContext&)
{
	
}

void ButtonPrefab::Update(const SceneContext&)
{
	
}