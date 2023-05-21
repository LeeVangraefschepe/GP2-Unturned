#pragma once
class BuildingPrefab final : public GameObject
{
public:
	BuildingPrefab(const std::wstring& path, BaseMaterial* material, const PxMaterial* physMaterial, XMFLOAT3 position, XMFLOAT3 rotation);
	~BuildingPrefab() override = default;

	BuildingPrefab(const BuildingPrefab& other) = delete;
	BuildingPrefab(BuildingPrefab&& other) noexcept = delete;
	BuildingPrefab& operator=(const BuildingPrefab& other) = delete;
	BuildingPrefab& operator=(BuildingPrefab&& other) noexcept = delete;
};

