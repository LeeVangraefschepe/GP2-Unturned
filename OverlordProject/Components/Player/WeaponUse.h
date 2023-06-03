#pragma once
#include "WeaponSlot.h"
#include "Components/Other/Health.h"
#include "Prefabs/Particles/HitParticle.h"

class WeaponUse : public BaseComponent, Observer<WeaponSlot>
{
	WeaponSlot* m_pWeaponSlot;
	HitParticle* m_pHitParticle{};

	bool OnHit(Health*& pHealth, XMFLOAT3& position);
public:
	WeaponUse(WeaponSlot* weaponSlot);
	~WeaponUse() override;

	WeaponUse(const WeaponUse& other) = delete;
	WeaponUse(WeaponUse&& other) noexcept = delete;
	WeaponUse& operator=(const WeaponUse& other) = delete;
	WeaponUse& operator=(WeaponUse&& other) noexcept = delete;

	void OnDestroy() override;
	void OnNotify(unsigned, WeaponSlot*) override;

	void Initialize(const SceneContext&) override;
};

