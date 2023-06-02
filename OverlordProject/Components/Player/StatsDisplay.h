#pragma once
#include "Components/Other/Health.h"

class StatsDisplay : public BaseComponent, Observer<Health>
{
	Health* m_health;
	GameObject* m_pBackground{};

	GameObject* m_pHealthDisplay{};
	GameObject* m_pHealthDisplayBackground{};

	GameObject* m_pStaminaDisplay{};
	GameObject* m_pStaminaDisplayBackground{};

	GameObject* m_pWaterDisplay{};
	GameObject* m_pWaterDisplayBackground{};

	GameObject* m_pFoodDisplay{};
	GameObject* m_pFoodDisplayBackground{};

	void CreateBar(const SceneContext& sceneContext, GameObject*& pDisplay, GameObject*& pDisplayBackground, float height, const XMFLOAT4& color) const;

public:
	StatsDisplay(Health* health);
	~StatsDisplay() override;

	StatsDisplay(const StatsDisplay& other) = delete;
	StatsDisplay(StatsDisplay&& other) noexcept = delete;
	StatsDisplay& operator=(const StatsDisplay& other) = delete;
	StatsDisplay& operator=(StatsDisplay&& other) noexcept = delete;

	void Initialize(const SceneContext& sceneContext) override;
	void Update(const SceneContext&) override;

	void OnNotify(unsigned, Health*) override;
	void OnDestroy() override;
};

