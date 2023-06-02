#pragma once
#include "Inventory.h"

class ItemPicker : public BaseComponent
{
public:
	ItemPicker(Inventory* inventory);
	~ItemPicker() override = default;

	ItemPicker(const ItemPicker& other) = delete;
	ItemPicker(ItemPicker&& other) noexcept = delete;
	ItemPicker& operator=(const ItemPicker& other) = delete;
	ItemPicker& operator=(ItemPicker&& other) noexcept = delete;

	void Initialize(const SceneContext& sceneContext) override;
	void Update(const SceneContext&) override;
private:
	Inventory* m_inventory{};
};