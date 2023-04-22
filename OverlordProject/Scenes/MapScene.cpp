#include "stdafx.h"
#include "MapScene.h"

#include "Materials/ColorMaterial.h"
#include "Materials/DiffuseMaterial.h"
#include "Materials/UberMaterial.h"
#include "Prefabs/BuildingPrefab.h"
#include "Prefabs/Character.h"

MapScene::MapScene() :
	GameScene(L"MapScene") {}

void MapScene::Initialize()
{
	m_SceneContext.settings.enableOnGUI = true;
	auto& pPhysx = PxGetPhysics();

	//Ground plane
	const auto pDefaultMaterial = pPhysx.createMaterial(0.5f, 0.5f, 0.5f);
	GameSceneExt::CreatePhysXGroundPlane(*this, pDefaultMaterial);

	//Materials
	const auto pMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial>();
	pMaterial->SetDiffuseTexture(L"Textures/Texture.png");
	//pMaterial->SetVariable_Vector(L"gColor", XMFLOAT4{ Colors::Green });

	//Character
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

	//Input character
	auto inputAction = InputAction(CharacterMoveLeft, InputState::down, 'A');
	m_SceneContext.pInput->AddInputAction(inputAction);

	inputAction = InputAction(CharacterMoveRight, InputState::down, 'D');
	m_SceneContext.pInput->AddInputAction(inputAction);

	inputAction = InputAction(CharacterMoveForward, InputState::down, 'W');
	m_SceneContext.pInput->AddInputAction(inputAction);

	inputAction = InputAction(CharacterMoveBackward, InputState::down, 'S');
	m_SceneContext.pInput->AddInputAction(inputAction);

	inputAction = InputAction(CharacterJump, InputState::pressed, VK_SPACE, -1, XINPUT_GAMEPAD_A);
	m_SceneContext.pInput->AddInputAction(inputAction);

	//Create simple building
	AddChild(new BuildingPrefab{ L"Meshes/Buildings/Model_0", pMaterial, pDefaultMaterial, XMFLOAT3{}, XMFLOAT3{} });
}

void MapScene::Update()
{
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