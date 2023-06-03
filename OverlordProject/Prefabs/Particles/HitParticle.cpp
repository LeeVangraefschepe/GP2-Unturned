#include "stdafx.h"
#include "HitParticle.h"

HitParticle::HitParticle()
{
	//Particle System
	ParticleEmitterSettings settings{};
	settings.velocity = { 0.f,-.5f,0.f };
	settings.minSize = 0.1f;
	settings.maxSize = 0.5f;
	settings.minEnergy = 1.f;
	settings.maxEnergy = 2.f;
	settings.minScale = 0.01f;
	settings.maxScale = 0.06f;
	settings.minEmitterRadius = 0.f;
	settings.maxEmitterRadius = 0.5f;
	settings.color = { 1.f,1.f,1.f, .6f };

	m_pParticle = AddComponent(new ParticleEmitterComponent(L"Textures/Particles/Smoke.png", settings, 20));
}

void HitParticle::SetParticle(const XMFLOAT3& position)
{
	GetTransform()->Translate(position);
	m_currentLifeTime = m_maxLifeTime;
	SetActive(true);
}

void HitParticle::Update(const SceneContext& sceneContext)
{
	m_currentLifeTime -= sceneContext.pGameTime->GetElapsed();
	if (m_currentLifeTime <= 0.f)
	{
		GetTransform()->Translate(XMFLOAT3{0,-100,0});
	}
}
