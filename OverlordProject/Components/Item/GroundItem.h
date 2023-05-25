#pragma once
#include "Items.h"

class GroundItem final : public BaseComponent
{
	Item m_itemId;
	std::wstring m_name;
	XMFLOAT3 m_position;
	static Item ParseString(const std::wstring& item);
public:
	GroundItem(const std::wstring& item, XMFLOAT3 position);
	~GroundItem() override = default;

	void Initialize(const SceneContext& sceneContext) override;
	Item GetItem() const { return m_itemId; }

	GroundItem(const GroundItem& other) = delete;
	GroundItem(GroundItem&& other) noexcept = delete;
	GroundItem& operator=(const GroundItem& other) = delete;
	GroundItem& operator=(GroundItem&& other) noexcept = delete;
};

