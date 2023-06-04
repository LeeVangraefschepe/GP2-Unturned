#pragma once
#include "Components/Other/Health.h"

class Food : public BaseComponent
{
	float m_maxSaturation;
	float m_currentSaturation;
	float m_drainPerSecond;
	Health* m_pHealth;
public:
	Food(Health* health, float maxSaturation, float drainPerSecond);
	~Food() override = default;

	void Eat(float saturation);

	void Initialize(const SceneContext& sceneContext) override;
	void Update(const SceneContext&) override;

	float GetSaturation() const;
	float GetMaxSaturation() const;

	Food(const Food& other) = delete;
	Food(Food&& other) noexcept = delete;
	Food& operator=(const Food& other) = delete;
	Food& operator=(Food&& other) noexcept = delete;
};

