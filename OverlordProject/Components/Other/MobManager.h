#pragma once
#include "Prefabs/Mob/Zombie.h"

class MobManager : public BaseComponent
{
public:
	MobManager(int level, GameObject* pPlayer);
	~MobManager() override = default;

	void Initialize(const SceneContext& sceneContext) override;

	void IncreaseSpawns(int amount) { m_maxSpawnsPerNight += amount; }
	void Spawn() const;
	void ActivateZombie(const XMFLOAT3& pos) const;

	MobManager(const MobManager& other) = delete;
	MobManager(MobManager&& other) noexcept = delete;
	MobManager& operator=(const MobManager& other) = delete;
	MobManager& operator=(MobManager&& other) noexcept = delete;
private:
	std::vector<Zombie*> m_mobs{};
	std::vector<XMFLOAT3> m_spawns{};
	GameObject* m_pPlayer{};
	int m_maxSpawnsPerNight{};
};

