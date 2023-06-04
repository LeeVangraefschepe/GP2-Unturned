#pragma once
#include "Energy.h"
#include "Food.h"
#include "Components/Other/Health.h"
#include "Materials/Post/PostBloodscale.h"

class StatsDisplay : public BaseComponent, Observer<Health>, Observer<Energy>
{
	PostBloodscale* m_pPostBloodscale{};

	Health* m_health;
	Energy* m_energy;
	Food* m_food;

	GameObject* m_pBackground{};

	GameObject* m_pHealthDisplay{};
	XMFLOAT4 m_healthColor{ 1.f,0.f,0.f,1.f };

	GameObject* m_pStaminaDisplay{};
	XMFLOAT4 m_staminaColor{ 1.f,1.f,0.3f,1.f };

	GameObject* m_pWaterDisplay{};
	XMFLOAT4 m_waterColor{ 0.f,0.f,1.f,1.f };

	GameObject* m_pFoodDisplay{};
	XMFLOAT4 m_foodColor{ 0.5f,0.4f,0.f,1.f };

	SpriteFont* m_pFont{};

	void CreateBar(const SceneContext& sceneContext, GameObject*& pDisplay, float height, const XMFLOAT4& color) const;

public:
	StatsDisplay(Health* health, Energy* energy, Food* food);
	~StatsDisplay() override;

	StatsDisplay(const StatsDisplay& other) = delete;
	StatsDisplay(StatsDisplay&& other) noexcept = delete;
	StatsDisplay& operator=(const StatsDisplay& other) = delete;
	StatsDisplay& operator=(StatsDisplay&& other) noexcept = delete;

	void Initialize(const SceneContext& sceneContext) override;
	void Update(const SceneContext&) override;
	void Draw(const SceneContext&) override;

	void OnNotify(unsigned, Health*) override;
	void OnNotify(unsigned, Energy*) override;
	void OnDestroy() override;
};

