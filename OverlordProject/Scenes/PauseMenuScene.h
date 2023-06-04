#pragma once
#include "Prefabs/UI/ButtonPrefab.h"

class PauseMenuScene : public GameScene
{
public:
	PauseMenuScene();
	~PauseMenuScene() override = default;

	PauseMenuScene(const PauseMenuScene& other) = delete;
	PauseMenuScene(PauseMenuScene&& other) noexcept = delete;
	PauseMenuScene& operator=(const PauseMenuScene& other) = delete;
	PauseMenuScene& operator=(PauseMenuScene&& other) noexcept = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void OnGUI() override;
	void PostInitialize() override;

private:
	ButtonPrefab* m_pButtonContinue{};
	ButtonPrefab* m_pButtonRestart{};
	ButtonPrefab* m_pButtonMainMenu{};
	ButtonPrefab* m_pButtonQuit{};
};

