#include "stdafx.h"
#include "Food.h"

Food::Food(Health* health, float maxSaturation, float drainPerSecond):
m_maxSaturation(maxSaturation),
m_drainPerSecond(drainPerSecond),
m_pHealth(health)
{
	m_currentSaturation = m_maxSaturation;
}

void Food::Eat(float saturation)
{
	m_currentSaturation += saturation;
	if (m_currentSaturation > m_maxSaturation)
	{
		m_currentSaturation = m_maxSaturation;
	}
}

void Food::Initialize(const SceneContext&)
{
}

void Food::Update(const SceneContext& sceneContext)
{
	const float deltaTime = sceneContext.pGameTime->GetElapsed();
	m_currentSaturation -= deltaTime * m_drainPerSecond;

	if (m_currentSaturation <= 0.f)
	{
		m_currentSaturation = 0.f;
		m_pHealth->Damage(deltaTime);
	}
}

float Food::GetSaturation() const
{
	return m_currentSaturation;
}

float Food::GetMaxSaturation() const
{
	return m_maxSaturation;
}
