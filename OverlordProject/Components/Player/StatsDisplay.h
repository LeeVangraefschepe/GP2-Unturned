#pragma once
#include "Components/Other/Health.h"

class StatsDisplay : public BaseComponent, Observer<Health>
{
	Health* m_health;
public:
	StatsDisplay(Health* health);
	~StatsDisplay() override;

	StatsDisplay(const StatsDisplay& other) = delete;
	StatsDisplay(StatsDisplay&& other) noexcept = delete;
	StatsDisplay& operator=(const StatsDisplay& other) = delete;
	StatsDisplay& operator=(StatsDisplay&& other) noexcept = delete;

	void Initialize(const SceneContext& sceneContext) override;

	void OnNotify(unsigned, Health*) override;
	void OnDestroy() override;
};

