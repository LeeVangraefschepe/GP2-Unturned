#include "stdafx.h"
#include "Player.h"

#include "Components/Other/Health.h"
#include "Components/Player/ItemPicker.h"
#include "Components/Player/StatsDisplay.h"

Player::Player(const XMFLOAT3& position)
{
	GetTransform()->Translate(position);
}

void Player::Initialize(const SceneContext& sceneContext)
{
	auto& pPhysx = PxGetPhysics();
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

	const auto health = m_pCharacter->AddComponent(new Health{ 100.f });
	m_pCharacter->AddComponent(new StatsDisplay{ health });

	auto inputAction = InputAction(CharacterMoveLeft, InputState::down, 'Q');
	sceneContext.pInput->AddInputAction(inputAction);
	inputAction = InputAction(CharacterMoveRight, InputState::down, 'D');
	sceneContext.pInput->AddInputAction(inputAction);
	inputAction = InputAction(CharacterMoveForward, InputState::down, 'Z');
	sceneContext.pInput->AddInputAction(inputAction);
	inputAction = InputAction(CharacterMoveBackward, InputState::down, 'S');
	sceneContext.pInput->AddInputAction(inputAction);
	inputAction = InputAction(CharacterJump, InputState::pressed, VK_SPACE, -1, XINPUT_GAMEPAD_A);
	sceneContext.pInput->AddInputAction(inputAction);
}