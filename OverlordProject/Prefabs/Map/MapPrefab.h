#pragma once
class MapPrefab : public GameObject
{
public:
	MapPrefab();
	~MapPrefab() override = default;

	MapPrefab(const MapPrefab& other) = delete;
	MapPrefab(MapPrefab&& other) noexcept = delete;
	MapPrefab& operator=(const MapPrefab& other) = delete;
	MapPrefab& operator=(MapPrefab&& other) noexcept = delete;
private:
	void CreateGroundPlane(const PxMaterial* physMaterial, const XMFLOAT3& size);
	void LoadRoad(const PxMaterial* physMaterial);
	void LoadHouses(const PxMaterial* physMaterial);
	void LoadItemSpawns();
};

