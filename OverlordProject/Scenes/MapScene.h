#pragma once
class MapScene : public GameScene
{
public:
	MapScene();
	~MapScene() override = default;

	MapScene(const MapScene& other) = delete;
	MapScene(MapScene&& other) noexcept = delete;
	MapScene& operator=(const MapScene& other) = delete;
	MapScene& operator=(MapScene&& other) noexcept = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void OnGUI() override;
	void PostInitialize() override;
};

