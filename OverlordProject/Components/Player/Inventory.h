#pragma once
#include "Items.h"

class Inventory : public BaseComponent
{
public:
	Inventory();
	~Inventory() override = default;

	Inventory(const Inventory& other) = delete;
	Inventory(Inventory&& other) noexcept = delete;
	Inventory& operator=(const Inventory& other) = delete;
	Inventory& operator=(Inventory&& other) noexcept = delete;

	void Initialize(const SceneContext& sceneContext) override;
	void AddItem(Item item);
	bool ConsumeItem(Item item);
	int GetAmountItem(Item item);
	int GetItemSize() const;
	Item GetItemBySlot(int slot) const;
private:
	std::map<Item, int> m_items{};
};

