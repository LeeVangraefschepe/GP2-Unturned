#include "stdafx.h"
#include "StatsDisplay.h"

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

	m_pHealthDisplay = new GameObject();
	m_pHealthDisplay->AddComponent(new SpriteComponent(L"Textures/UI/HealthBar.png", { 0.0f,0.0f }, { 1.f,1.f,1.f,.5f }));
	scene->AddChild(m_pHealthDisplay);
	m_pHealthDisplay->GetTransform()->Translate(0.f, sceneContext.windowHeight - 200, .0f);
	

	m_pBackground = new GameObject();
	m_pBackground->AddComponent(new SpriteComponent(L"Textures/UI/StatsBars.png", { 0.f,0.f }, { 1.f,1.f,1.f,.5f }));
	scene->AddChild(m_pBackground);
	m_pBackground->GetTransform()->Translate(0.f, sceneContext.windowHeight - 250, .0f);
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
