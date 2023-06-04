#include "stdafx.h"
#include "WeaponSlot.h"

#include "Components/Item/GroundItem.h"

WeaponSlot::WeaponSlot(Inventory* inventory):
	m_inventory(inventory)
{
}

Item WeaponSlot::GetSelectedItem() const
{
	return m_inventory->GetItemBySlot(m_currentSlot);
}

void WeaponSlot::Initialize(const SceneContext&)
{
	m_pFont = ContentManager::Load<SpriteFont>(L"SpriteFonts/Minecraft_32.fnt");
}

void WeaponSlot::Update(const SceneContext&)
{
	const int maxSlot = m_inventory->GetItemSize();
	if (InputManager::IsKeyboardKey(InputState::pressed, VK_UP))
	{
		++m_currentSlot;
		if (m_currentSlot >= maxSlot)
		{
			m_currentSlot = 0;
		}
		m_subject->Notify(Swap, this);
	}
	else if (InputManager::IsKeyboardKey(InputState::pressed, VK_DOWN))
	{
		--m_currentSlot;
		if (m_currentSlot < 0)
		{
			m_currentSlot = maxSlot - 1;
		}
		if (m_currentSlot < 0)
		{
			m_currentSlot = 0;
		}
		m_subject->Notify(Swap, this);
	}

	if (InputManager::IsMouseButton(InputState::pressed, 1) || InputManager::IsKeyboardKey(InputState::pressed, 'Y'))
	{
		Fire();
	}
}

void WeaponSlot::Draw(const SceneContext& sceneContext)
{
	std::wstringstream ss{};
	if (m_inventory->GetItemSize() == 0)
	{
		ss << L"NONE";
	}
	else
	{
		std::wstring itemName{};
		const Item currentItem = m_inventory->GetItemBySlot(m_currentSlot);
		GroundItem::ParseItem(currentItem, itemName);
		ss << itemName << L": " << m_inventory->GetAmountItem(currentItem);
	}

	TextRenderer::Get()->DrawText(m_pFont, ss.str(), { 0,sceneContext.windowHeight - 250 }, XMFLOAT4{ Colors::White });
}

void WeaponSlot::Fire()
{
	if (m_inventory->GetItemSize() == 0) { return; }

	const Item currentItem = m_inventory->GetItemBySlot(m_currentSlot);

	const int amount = m_inventory->GetAmountItem(currentItem);

	if (amount <= 0) { return; }

	const bool isLastUse = amount == 1;

	m_subject->Notify(Use, this);

	m_inventory->ConsumeItem(currentItem);

	if (isLastUse)
	{
		m_currentSlot = 0;
	}
}
