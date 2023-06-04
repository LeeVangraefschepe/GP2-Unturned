#include "stdafx.h"
#include "Inventory.h"

Inventory::Inventory()
{
}

void Inventory::Initialize(const SceneContext&)
{
}

void Inventory::AddItem(Item item, int amount)
{
	if (!m_items.contains(item))
	{
		m_items.emplace(item, amount);
		return;
	}
	m_items[item] += amount;
}

bool Inventory::ConsumeItem(Item item)
{
	if (!m_items.contains(item))
	{
		return false;
	}

	auto& itemCount = m_items[item];
	if (itemCount <= 0) { return false; }

	--itemCount;

	if (itemCount == 0)
	{
		m_items.erase(item);
	}
	
	return true;
}

int Inventory::GetAmountItem(Item item)
{
	if (!m_items.contains(item))
	{
		return -1;
	}
	return m_items[item];
}

int Inventory::GetItemSize() const
{
	return static_cast<int>(m_items.size());
}

Item Inventory::GetItemBySlot(int slot) const
{
	auto iterator = m_items.begin();
	std::advance(iterator, slot);
	return iterator->first;
}
