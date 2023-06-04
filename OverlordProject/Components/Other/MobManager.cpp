#include "stdafx.h"
#include "MobManager.h"

#include "Parser/WorldParser.h"
#include "Prefabs/Mob/Zombie.h"

MobManager::MobManager(int level, GameObject* pPlayer):
m_pPlayer(pPlayer)
{
	constexpr WorldParser parser{};
	std::wstringstream ss{};
	ss << L"Resources/Maps/" << level << L"/Zombie.data";
	m_spawns = parser.ZombieLoader(ss.str());

	
	//for (const auto& spawn : m_spawns)
	//{
	//	std::cout << spawn.x << ", " << spawn.y << ", " << spawn.z << "\n";
	//}
}

void MobManager::Initialize(const SceneContext&)
{
	const auto scene = GetScene();
	constexpr int maxZombies = 50;
	for (int i{}; i < maxZombies; ++i)
	{
		auto zombie = new Zombie{ {0,-100,0}, m_pPlayer };
		scene->AddChild(zombie);
		zombie->SetActive(false);
		m_mobs.emplace_back(zombie);
	}
}

void MobManager::Spawn() const
{
	const int spawnPointsSize = static_cast<int>(m_spawns.size());
	for (int i{}; i < m_maxSpawnsPerNight; ++i)
	{
		ActivateZombie(m_spawns[rand() % spawnPointsSize]);
	}
}

void MobManager::ActivateZombie(const XMFLOAT3& pos) const
{
	for (const auto& zombie : m_mobs)
	{
		if (zombie->GetActive() == false)
		{
			zombie->SetActive(true);
			zombie->Set(pos, 1.f);
			return;
		}
	}
}
