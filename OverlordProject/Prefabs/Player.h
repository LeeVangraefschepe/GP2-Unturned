#pragma once
#include "Character.h"
class Player final : public GameObject
{
	enum InputIds
	{
		CharacterMoveLeft,
		CharacterMoveRight,
		CharacterMoveForward,
		CharacterMoveBackward,
		CharacterJump
	};

	Character* m_pCharacter{};
public:
	Player(const XMFLOAT3& position);
	~Player() override = default;

	void Initialize(const SceneContext&) override;

	Player(const Player& other) = delete;
	Player(Player&& other) noexcept = delete;
	Player& operator=(const Player& other) = delete;
	Player& operator=(Player&& other) noexcept = delete;
};

