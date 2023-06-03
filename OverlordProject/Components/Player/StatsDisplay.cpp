#include "stdafx.h"
#include "StatsDisplay.h"

void StatsDisplay::CreateBar(const SceneContext& sceneContext, GameObject*& pDisplay, float height, const XMFLOAT4& color) const
{
	const auto scene = GetScene();

	pDisplay = new GameObject();
	pDisplay->AddComponent(new SpriteComponent(L"Textures/UI/Bar.png", { 0.0f,0.0f }, color));
	scene->AddChild(pDisplay);
	pDisplay->GetTransform()->Translate(75.f, sceneContext.windowHeight - height, .1f);

	const auto pDisplayBackground = new GameObject();
	pDisplayBackground->AddComponent(new SpriteComponent(L"Textures/UI/Bar.png", { 0.0f,0.0f }, { 0.f,0.f,0.f,0.8f }));
	scene->AddChild(pDisplayBackground);
	pDisplayBackground->GetTransform()->Translate(75.f, sceneContext.windowHeight - height, .1f);
}

StatsDisplay::StatsDisplay(Health* health, Energy* energy):
	m_health(health),
	m_energy(energy)
{
	m_health->GetSubject()->AddObserver(this);
	m_energy->GetSubject()->AddObserver(this);
}

StatsDisplay::~StatsDisplay()
{
	if (m_health)
	{
		m_health->GetSubject()->RemoveObserver(this);
	}
	if (m_energy)
	{
		m_energy->GetSubject()->RemoveObserver(this);
	}
}

void StatsDisplay::Initialize(const SceneContext& sceneContext)
{
	const auto scene = GetScene();

	m_pPostBloodscale = MaterialManager::Get()->CreateMaterial<PostBloodscale>();
	scene->AddPostProcessingEffect(m_pPostBloodscale);

	CreateBar(sceneContext, m_pHealthDisplay, 230, m_healthColor);
	CreateBar(sceneContext, m_pStaminaDisplay, 170, m_staminaColor);
	CreateBar(sceneContext, m_pWaterDisplay, 110, m_waterColor);
	CreateBar(sceneContext, m_pFoodDisplay, 50, m_foodColor);

	m_pBackground = new GameObject();
	m_pBackground->AddComponent(new SpriteComponent(L"Textures/UI/StatsBars.png", { 0.f,0.f }, { 1.f,1.f,1.f,1.f }));
	scene->AddChild(m_pBackground);
	m_pBackground->GetTransform()->Translate(0.f, sceneContext.windowHeight - 250, .1f);
}

void StatsDisplay::OnNotify(unsigned, Health*)
{
	const float healthPerc = m_health->GetHealth() / m_health->GetMaxHealth();
	m_pHealthDisplay->GetTransform()->Scale(healthPerc, 1.f, 1.f);
	m_pPostBloodscale->SetAmount((healthPerc - 1.f) * -1.f);
}

void StatsDisplay::OnNotify(unsigned type, Energy*)
{
	switch (static_cast<Energy::Events>(type))
	{
	case Energy::regen:
		m_pStaminaDisplay->GetComponent<SpriteComponent>()->SetColor(m_staminaColor);
	case Energy::consume:
		m_pStaminaDisplay->GetTransform()->Scale(m_energy->GetEnergy() / m_energy->GetMaxEnergy(), 1.f, 1.f);
		break;
	case Energy::fail:
		m_pStaminaDisplay->GetComponent<SpriteComponent>()->SetColor(XMFLOAT4{ Colors::Red });
		break;
	}
	
}

void StatsDisplay::OnDestroy()
{
	m_health = nullptr;
	m_energy = nullptr;
}
