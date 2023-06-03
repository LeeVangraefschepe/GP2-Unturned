#include "stdafx.h"
#include "MapScene.h"

#include "Prefabs/Character.h"
#include "Prefabs/Player.h"
#include "Prefabs/Map/MapPrefab.h"
#include "Prefabs/Mob/Zombie.h"

MapScene::MapScene() :
	GameScene(L"MapScene") {}

void MapScene::Initialize()
{
	m_SceneContext.pLights->SetDirectionalLight({ -950.6139526f,66.1346436f,-410.1850471f }, { 0.740129888f, -0.597205281f, 0.309117377f });
	m_SceneContext.pLights->GetDirectionalLight().intensity = 0.1f;

	m_SceneContext.settings.enableOnGUI = true;
	m_SceneContext.settings.vSyncEnabled = false;

	m_pCharacter = AddChild(new Player{ {} })->GetPlayerCharacter();

	m_pMap = AddChild(new MapPrefab{});

	AddChild(new Zombie{ {10,0,10}, m_pCharacter});
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