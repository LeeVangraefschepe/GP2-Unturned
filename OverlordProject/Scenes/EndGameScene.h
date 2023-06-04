#pragma once
#include "Prefabs/UI/ButtonPrefab.h"

class EndGameScene : public GameScene
{
public:
	EndGameScene();
	~EndGameScene() override = default;

	EndGameScene(const EndGameScene& other) = delete;
	EndGameScene(EndGameScene&& other) noexcept = delete;
	EndGameScene& operator=(const EndGameScene& other) = delete;
	EndGameScene& operator=(EndGameScene&& other) noexcept = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void OnGUI() override;
	void PostInitialize() override;

private:
	ButtonPrefab* m_pButtonContinue{};
};

