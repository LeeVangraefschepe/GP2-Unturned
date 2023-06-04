#pragma once
#include "Character.h"
#include "Components/Other/Health.h"

class Player final : public GameObject, Observer<Health>
{
	enum InputIds
	{
		CharacterMoveLeft,
		CharacterMoveRight,
		CharacterMoveForward,
		CharacterMoveBackward,
		CharacterJump,
		CharacterSprint
	};

	Character* m_pCharacter{};

	Health* m_pHealth{};
	void OnNotify(unsigned, Health*) override;

	const float m_shakeDuration{0.5f};
	float m_currentShakeDuration{};
public:
	Player(const XMFLOAT3& position);
	~Player() override = default;

	void Initialize(const SceneContext&) override;
	void Update(const SceneContext&) override;

	Character* GetPlayerCharacter() const { return m_pCharacter; }

	Player(const Player& other) = delete;
	Player(Player&& other) noexcept = delete;
	Player& operator=(const Player& other) = delete;
	Player& operator=(Player&& other) noexcept = delete;
};

