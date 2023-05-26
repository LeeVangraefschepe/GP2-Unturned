#pragma once
class Zombie final : public GameObject
{
	ModelAnimator* m_pAnimator{ nullptr };
	RigidBodyComponent* m_pRigidBody{ nullptr };
	int m_animationClipId{}, m_lastAnimationClipId{-1};

	void UpdateAnimation();

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

