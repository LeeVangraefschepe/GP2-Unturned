#include "stdafx.h"
#include "MapScene.h"

#include "Components/Player/ItemPicker.h"
#include "Materials/ColorMaterial.h"
#include "Materials/DiffuseMaterial.h"
#include "Materials/UberMaterial.h"
#include "Prefabs/Map/BuildingPrefab.h"
#include "Prefabs/Character.h"
#include "Prefabs/Map/MapPrefab.h"

MapScene::MapScene() :
	GameScene(L"MapScene") {}

void MapScene::Initialize()
{
	m_SceneContext.pLights->SetDirectionalLight({ -950.6139526f,66.1346436f,-410.1850471f }, { 0.740129888f, -0.597205281f, 0.309117377f });

	m_SceneContext.settings.enableOnGUI = true;
	m_SceneContext.settings.vSyncEnabled = false;
	auto& pPhysx = PxGetPhysics();

	//Ground plane
	const auto pDefaultMaterial = pPhysx.createMaterial(0.5f, 0.5f, 0.5f);

	//Characters
	CharacterDesc characterDesc{ pDefaultMaterial };
	characterDesc.rotationSpeed = 20.f;
	characterDesc.maxMoveSpeed = 7.5f;
	characterDesc.actionId_MoveForward = CharacterMoveForward;
	characterDesc.actionId_MoveBackward = CharacterMoveBackward;
	characterDesc.actionId_MoveLeft = CharacterMoveLeft;
	characterDesc.actionId_MoveRight = CharacterMoveRight;
	characterDesc.actionId_Jump = CharacterJump;
	m_pCharacter = AddChild(new Character(characterDesc));
	m_pCharacter->GetTransform()->Translate(0.f, 10.f, 0.f);

	m_pCharacter->AddComponent(new ItemPicker{});

	auto inputAction = InputAction(CharacterMoveLeft, InputState::down, 'Q');
	m_SceneContext.pInput->AddInputAction(inputAction);
	inputAction = InputAction(CharacterMoveRight, InputState::down, 'D');
	m_SceneContext.pInput->AddInputAction(inputAction);
	inputAction = InputAction(CharacterMoveForward, InputState::down, 'Z');
	m_SceneContext.pInput->AddInputAction(inputAction);
	inputAction = InputAction(CharacterMoveBackward, InputState::down, 'S');
	m_SceneContext.pInput->AddInputAction(inputAction);
	inputAction = InputAction(CharacterJump, InputState::pressed, VK_SPACE, -1, XINPUT_GAMEPAD_A);
	m_SceneContext.pInput->AddInputAction(inputAction);

	m_pMap = new MapPrefab{};
	AddChild(m_pMap);
}

void MapScene::Update()
{
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