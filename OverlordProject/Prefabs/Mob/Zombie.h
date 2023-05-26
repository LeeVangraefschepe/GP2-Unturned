#pragma once
class Zombie final : public GameObject
{
	ModelAnimator* m_pAnimator{ nullptr };
	RigidBodyComponent* m_pRigidBody{ nullptr };
	GameObject* m_pVisuals{ nullptr };
	ControllerComponent* m_pControllerComponent{ nullptr };

	XMFLOAT3 m_totalVelocity{};
	float m_fallAcceleration{50.f};

	int m_animationClipId{}, m_lastAnimationClipId{-1};

	void UpdateAnimation();
	void UpdateMovement(const XMVECTOR& direction, const XMFLOAT3& playerPosition, float deltaTime);

public:
	Zombie(const XMFLOAT3& position);
	~Zombie() override = default;

	void Initialize(const SceneContext&) override;
	void Update(const SceneContext&) override;

	Zombie(const Zombie& other) = delete;
	Zombie(Zombie&& other) noexcept = delete;
	Zombie& operator=(const Zombie& other) = delete;
	Zombie& operator=(Zombie&& other) noexcept = delete;
};

