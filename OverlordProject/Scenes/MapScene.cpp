#include "stdafx.h"
#include "MapScene.h"

#include "Prefabs/Character.h"
#include "Prefabs/Player.h"
#include "Prefabs/Map/MapPrefab.h"
#include "Prefabs/Mob/Zombie.h"
#include "Prefabs/Overlord/CubePrefab.h"

MapScene::MapScene() :
	GameScene(L"MapScene") {}

void MapScene::Initialize()
{
	m_SceneContext.pLights->SetDirectionalLight({ -950.6139526f,66.1346436f,-410.1850471f }, { 0.740129888f, -0.597205281f, 0.309117377f });

	m_SceneContext.settings.enableOnGUI = true;
	m_SceneContext.settings.vSyncEnabled = false;

	m_pCharacter = AddChild(new Player{ {} })->GetPlayerCharacter();

	m_pMap = AddChild(new MapPrefab{});

	AddChild(new Zombie{ {10,0,10}, m_pCharacter});

	auto& pPhysx = PxGetPhysics();
	const auto pDefaultMaterial = pPhysx.createMaterial(0.f, 0.f, 1.f);

	const auto m_pRightWall = new CubePrefab{ {10,10,10}, XMFLOAT4{Colors::White} };
	const auto rigidbody = m_pRightWall->AddComponent(new RigidBodyComponent{ true });
	rigidbody->AddCollider(PxBoxGeometry{ 5, 5, 5 }, *pDefaultMaterial, false);
	AddChild(m_pRightWall);
}

void MapScene::Update()
{
	InputManager::SetForceMouseToCenter(true);
	if (InputManager::IsKeyboardKey(InputState::pressed, 'R'))
	{
		RemoveChild(m_pMap, true);
		m_pMap = new MapPrefab{};
		AddChild(m_pMap);
	}
}

void MapScene::Draw()
{
}

void MapScene::OnGUI()
{
	m_pCharacter->DrawImGui();
}

void MapScene::PostInitialize()
{
}