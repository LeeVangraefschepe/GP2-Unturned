#include "stdafx.h"
#include "StatsDisplay.h"

void StatsDisplay::CreateBar(const SceneContext& sceneContext, GameObject*& pDisplay, GameObject*& pDisplayBackground, float height, const XMFLOAT4& color) const
{
	const auto scene = GetScene();

	pDisplay = new GameObject();
	pDisplay->AddComponent(new SpriteComponent(L"Textures/UI/Bar.png", { 0.0f,0.0f }, color));
	scene->AddChild(pDisplay);
	pDisplay->GetTransform()->Translate(75.f, sceneContext.windowHeight - height, .1f);

	pDisplayBackground = new GameObject();
	pDisplayBackground->AddComponent(new SpriteComponent(L"Textures/UI/Bar.png", { 0.0f,0.0f }, { 0.f,0.f,0.f,0.8f }));
	scene->AddChild(pDisplayBackground);
	pDisplayBackground->GetTransform()->Translate(75.f, sceneContext.windowHeight - height, .1f);
}

StatsDisplay::StatsDisplay(Health* health):
	m_health(health)
{
	m_health->GetSubject()->AddObserver(this);
}

StatsDisplay::~StatsDisplay()
{
	if (m_health)
	{
		m_health->GetSubject()->RemoveObserver(this);
	}
}

void StatsDisplay::Initialize(const SceneContext& sceneContext)
{
	const auto scene = GetScene();

	CreateBar(sceneContext, m_pHealthDisplay, m_pHealthDisplayBackground, 230, { 1.f,0.f,0.f,1.f });

	CreateBar(sceneContext, m_pStaminaDisplay, m_pStaminaDisplayBackground, 170, { 1.f,1.f,0.3f,1.f });

	CreateBar(sceneContext, m_pWaterDisplay, m_pWaterDisplayBackground, 110, { 0.f,0.f,1.f,1.f });

	CreateBar(sceneContext, m_pFoodDisplay, m_pFoodDisplayBackground, 50, { 0.5f,0.4f,0.f,1.f });

	m_pBackground = new GameObject();
	m_pBackground->AddComponent(new SpriteComponent(L"Textures/UI/StatsBars.png", { 0.f,0.f }, { 1.f,1.f,1.f,.5f }));
	scene->AddChild(m_pBackground);
	m_pBackground->GetTransform()->Translate(0.f, sceneContext.windowHeight - 250, .1f);
}

void StatsDisplay::Update(const SceneContext&)
{
	
}

void StatsDisplay::OnNotify(unsigned eventId, Health*)
{
	switch (static_cast<Health::Events>(eventId))
	{
	case Health::damage:
		m_pHealthDisplay->GetTransform()->Scale(m_health->GetHealth() / m_health->GetMaxHealth(), 1.f, 1.f);
		m_pStaminaDisplay->GetTransform()->Scale(m_health->GetHealth() / m_health->GetMaxHealth(), 1.f, 1.f);
		break;
	case Health::died:
		std::cout << "Player died\n";
		break;
	}
}

void StatsDisplay::OnDestroy()
{
	m_health = nullptr;
}
