#pragma once
class GroundItemPrefab : public GameObject
{
public:
	GroundItemPrefab();
	~GroundItemPrefab() override = default;

	GroundItemPrefab(const GroundItemPrefab& other) = delete;
	GroundItemPrefab(GroundItemPrefab&& other) noexcept = delete;
	GroundItemPrefab& operator=(const GroundItemPrefab& other) = delete;
	GroundItemPrefab& operator=(GroundItemPrefab&& other) noexcept = delete;
};

