#include "stdafx.h"
#include "Player.h"

#include "Components/Other/Health.h"
#include "Components/Player/Food.h"
#include "Components/Player/Inventory.h"
#include "Components/Player/ItemPicker.h"
#include "Components/Player/StatsDisplay.h"
#include "Components/Player/WeaponSlot.h"
#include "Components/Player/WeaponUse.h"

void Player::OnNotify(unsigned event, Health*)
{
	if (event != Health::Events::damage) { return; }
	m_pCharacter->SetShake(true);
	m_currentShakeDuration = m_shakeDuration;
}

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
	characterDesc.actionId_Sprint = CharacterSprint;
	m_pCharacter = AddChild(new Character(characterDesc));
	m_pCharacter->GetTransform()->Translate(0.f, 10.f, 0.f);

	const auto inventory = m_pCharacter->AddComponent(new Inventory{});
	m_pCharacter->AddComponent(new ItemPicker{ inventory });

	const auto weaponSlot = m_pCharacter->AddComponent(new WeaponSlot{ inventory });
	m_pCharacter->AddComponent(new WeaponUse{ weaponSlot });

	m_pHealth = m_pCharacter->AddComponent(new Health{ 100.f });
	const auto food = m_pCharacter->AddComponent(new Food{ m_pHealth, 100.f, 0.8f });
	const auto energy = m_pCharacter->AddComponent(new Energy{ food,5.f,2.f });
	m_pHealth->GetSubject()->AddObserver(this);

	
	m_pCharacter->AddComponent(new StatsDisplay{ m_pHealth, energy, food });
	m_pCharacter->SetEnergy(energy);

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
	inputAction = InputAction(CharacterSprint, InputState::down, VK_SHIFT, -1, XINPUT_GAMEPAD_A);
	sceneContext.pInput->AddInputAction(inputAction);
}

void Player::Update(const SceneContext& sceneContext)
{
	m_currentShakeDuration -= sceneContext.pGameTime->GetElapsed();
	if (m_currentShakeDuration < 0.f)
	{
		m_pCharacter->SetShake(false);
	}
}
