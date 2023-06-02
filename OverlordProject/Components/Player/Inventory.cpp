#include "stdafx.h"
#include "Inventory.h"

Inventory::Inventory()
{
}

void Inventory::Initialize(const SceneContext&)
{
}

void Inventory::AddItem(Item item)
{
	if (!m_items.contains(item))
	{
		m_items.emplace(item, 1);
		return;
	}
	++m_items[item];
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
	return true;
}
