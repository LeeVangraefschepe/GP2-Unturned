#pragma once

class GroundItem final : public GameObject
{
	XMFLOAT3 m_position;
	bool m_showToolInfo{};
public:
	GroundItem(const std::wstring& item, XMFLOAT3 position);
	~GroundItem() override = default;

	void Update(const SceneContext&) override;

	GroundItem(const GroundItem& other) = delete;
	GroundItem(GroundItem&& other) noexcept = delete;
	GroundItem& operator=(const GroundItem& other) = delete;
	GroundItem& operator=(GroundItem&& other) noexcept = delete;
};

