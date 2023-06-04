#include "stdafx.h"
#include "TimeManager.h"

float TimeManager::GetDaylightIntensity() const
{
	// Calculate the normalized time of the day (-1 to 1)
	const float normalizedTime = (m_currentDayTime / m_totalDayTime) * 2.0f - 1.0f;

	// Set the minimum and maximum light intensities for the day
	constexpr float minIntensity = 0.01f;
	constexpr float maxIntensity = 1.0f;

	return minIntensity + (maxIntensity - minIntensity) * (1.0f - std::abs(normalizedTime));
}

bool TimeManager::IsNight() const
{
	const float progress = m_currentDayTime / m_totalDayTime;
	return progress < 0.2f || progress > 0.75f;
}

void TimeManager::Update(const SceneContext& sceneContext)
{
	m_currentDayTime += sceneContext.pGameTime->GetElapsed();
	if (m_currentDayTime >= m_totalDayTime)
	{
		m_dayCount++;
		m_currentDayTime = 0.f;
	}

	sceneContext.pLights->GetDirectionalLight().intensity = GetDaylightIntensity();
	sceneContext.pLights->GetDirectionalLight().direction.x = m_currentDayTime / m_totalDayTime * XM_PI;
	//std::cout << "Daycount: " << m_dayCount << "\n";
}
