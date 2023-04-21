#include "stdafx.h"
#include "ButtonPrefab.h"

ButtonPrefab::ButtonPrefab(const std::wstring& texture, XMFLOAT2 dimensions) :
m_dimensions(dimensions)
{
	m_pSpriteComp = AddComponent(new SpriteComponent(texture, { 0.f,0.f }, { 1.f,1.f,1.f,1.f }));
	m_pSpriteComp->SetDimensions(dimensions.x, dimensions.y);
	m_pFont = ContentManager::Load<SpriteFont>(L"SpriteFonts/Consolas_32.fnt");
}

void ButtonPrefab::Initialize(const SceneContext&)
{
	
}

void ButtonPrefab::Update(const SceneContext&)
{
	TextRenderer::Get()->DrawText(m_pFont, StringUtil::utf8_decode("Hello world!"), XMFLOAT2{50,50}, { 1.f,1.f,1.f,1.f });
	auto& mousePos = InputManager::GetMousePosition();
	auto& position = GetTransform()->GetPosition();

	if (mousePos.x >= position.x && mousePos.x <= position.x + m_dimensions.x &&
		mousePos.y >= position.y && mousePos.y <= position.y + m_dimensions.y)
	{
		if (InputManager::IsMouseButton(InputState::released, 1))
		{
			std::cout << "Clicked\n";
		}
	}
}