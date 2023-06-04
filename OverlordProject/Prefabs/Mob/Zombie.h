#pragma once
#include "Components/Other/Health.h"

class Zombie final : public GameObject, Observer<Health>
{
	ModelAnimator* m_pAnimator{ nullptr };
	GameObject* m_pVisuals{ nullptr };
	ControllerComponent* m_pControllerComponent{ nullptr };

	XMFLOAT3 m_totalVelocity{};
	float m_fallAcceleration{50.f};

	Health* m_playerHealth{ nullptr };
	float m_damage{10.f};
	float m_attackDelay{ 2.f };
	float m_currentAttackDelay{};

	int m_animationClipId{}, m_lastAnimationClipId{-1};

	void UpdateAnimation();
	void UpdateMovement(const XMVECTOR& direction, const XMFLOAT3& playerPosition, float deltaTime);
	void UpdateAttack(float distance, const XMFLOAT3& playerPosition);

	bool m_active{ true };

	void OnNotify(unsigned, Health*) override;

	inline static FMOD::Sound* m_biteSound{nullptr};
	inline static FMOD::Sound* m_hitSound{nullptr};
	FMOD::Channel* m_channel{nullptr};
	void PlayBiteSound();
	void PlayHitSound();

public:
	Zombie(const XMFLOAT3& position, GameObject* target);
	~Zombie() override = default;

	void Initialize(const SceneContext&) override;
	void Update(const SceneContext&) override;

	Zombie(const Zombie& other) = delete;
	Zombie(Zombie&& other) noexcept = delete;
	Zombie& operator=(const Zombie& other) = delete;
	Zombie& operator=(Zombie&& other) noexcept = delete;
};

