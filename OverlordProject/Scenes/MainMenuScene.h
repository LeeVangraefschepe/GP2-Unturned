#pragma once
class ButtonPrefab;

class MainMenuScene : public GameScene
{
public:
	MainMenuScene();
	~MainMenuScene() override = default;

	MainMenuScene(const MainMenuScene& other) = delete;
	MainMenuScene(MainMenuScene&& other) noexcept = delete;
	MainMenuScene& operator=(const MainMenuScene& other) = delete;
	MainMenuScene& operator=(MainMenuScene&& other) noexcept = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void OnGUI() override;
	void PostInitialize() override;
private:
	ButtonPrefab* m_pButtonStart{};
	ButtonPrefab* m_pButtonQuit{};
	float m_TotalRotation{};
};
