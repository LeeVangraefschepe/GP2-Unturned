#pragma once
#include "MobManager.h"

class TimeManager : public BaseComponent
{
	float m_currentDayTime{};
	const float m_totalDayTime{30.f};
	int m_dayCount{};

	float GetDaylightIntensity() const;
	bool IsNight() const;
	MobManager* m_pMobManager;
public:
	TimeManager(MobManager* pMobManager);
	~TimeManager() override = default;

	void Initialize(const SceneContext&) override{}
	void Update(const SceneContext&) override;

	TimeManager(const TimeManager& other) = delete;
	TimeManager(TimeManager&& other) noexcept = delete;
	TimeManager& operator=(const TimeManager& other) = delete;
	TimeManager& operator=(TimeManager&& other) noexcept = delete;
};

