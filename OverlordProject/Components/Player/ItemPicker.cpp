#include "stdafx.h"
#include "ItemPicker.h"

#include "ScoreManager.h"
#include "../Item/GroundItem.h"

ItemPicker::ItemPicker(Inventory* inventory)
{
	m_inventory = inventory;
}

void ItemPicker::Initialize(const SceneContext&)
{
}

void ItemPicker::Update(const SceneContext& sceneContext)
{
	const auto pCamera = sceneContext.pCamera;
	const XMFLOAT3 cameraPos = pCamera->GetTransform()->GetWorldPosition();
	const XMFLOAT3 cameraForward = pCamera->GetTransform()->GetForward();

	constexpr float maxDistance{ 5.f };

	//Convert the PxVec3
	const PxVec3 rayOrigin{ cameraPos.x, cameraPos.y, cameraPos.z };
	const PxVec3 rayDirection{ cameraForward.x, cameraForward.y, cameraForward.z };

	//Filter for groups
	PxQueryFilterData filterData{};
	filterData.data.word0 = static_cast<UINT>(CollisionGroup::Group2);

	//Raycast
	if (PxRaycastBuffer hit{}; GetScene()->GetPhysxProxy()->Raycast(rayOrigin, rayDirection.getNormalized(), maxDistance, hit, PxHitFlag::eDEFAULT, filterData))
	{
		const auto gameobject = static_cast<BaseComponent*>(hit.block.actor->userData)->GetGameObject();
		if (InputManager::IsKeyboardKey(InputState::pressed, 'F'))
		{
			if (const auto groundItem = gameobject->GetComponent<GroundItem>())
			{
				const auto item = groundItem->GetItem();
				if (item == pistol)
				{
					m_inventory->AddItem(item, 5);
				}
				else
				{
					m_inventory->AddItem(item, 1);
				}
				ScoreManager::Get()->AddScore(10);
				std::cout << "Picked up item: " << groundItem->GetItem() << "\n";
			}
			
			gameobject->GetParent()->RemoveChild(gameobject, true);
		}
	}
}
