#pragma once
class HitParticle : public GameObject
{
	ParticleEmitterComponent* m_pParticle{};
	const float m_maxLifeTime{ 0.5f };
	float m_currentLifeTime{ 0.f };
	bool m_disabled{};
public:
	HitParticle();
	~HitParticle() override = default;

	void SetParticle(const XMFLOAT3& position);
	void Update(const SceneContext&) override;

	HitParticle(const HitParticle& other) = delete;
	HitParticle(HitParticle&& other) noexcept = delete;
	HitParticle& operator=(const HitParticle& other) = delete;
	HitParticle& operator=(HitParticle&& other) noexcept = delete;
};