#include "stdafx.h"
#include "Energy.h"
#include "Food.h"

Energy::Energy(Food* pFood ,float maxEnergy, float regenCooldown) :
m_maxEnergy(maxEnergy),
m_maxRegenCooldown(regenCooldown),
m_pFood(pFood)
{
	m_currentEnergy = m_maxEnergy;
	m_currentRegenCooldown = 0.f;
}

void Energy::Initialize(const SceneContext&)
{
}

void Energy::Update(const SceneContext& sceneContext)
{
	const float deltaTime = sceneContext.pGameTime->GetElapsed();
	if (m_currentRegenCooldown > 0.f)
	{
		m_currentRegenCooldown -= deltaTime;
		return;
	}

	if (m_currentEnergy < m_maxEnergy)
	{
		m_currentEnergy += deltaTime;
		m_pFood->Hunger(deltaTime*2.5f);
		m_subject->Notify(regen, this);
	}
}

bool Energy::ConsumeEnergy(float amount)
{
	if (m_currentEnergy < amount)
	{
		m_subject->Notify(fail, this);
		return false;
	}
	m_currentEnergy -= amount;
	m_currentRegenCooldown = m_maxRegenCooldown;
	m_subject->Notify(consume, this);
	return true;
}
