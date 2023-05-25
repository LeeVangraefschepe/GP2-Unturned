#include "stdafx.h"
#include "ItemPicker.h"

#include "../Item/GroundItem.h"

ItemPicker::ItemPicker()
{
}

void ItemPicker::Initialize(const SceneContext&)
{
}

void ItemPicker::Update(const SceneContext& sceneContext)
{
	auto pCamera = sceneContext.pCamera;
	XMFLOAT3 cameraPos = pCamera->GetTransform()->GetWorldPosition();
	XMFLOAT3 cameraForward = pCamera->GetTransform()->GetForward();

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
		auto gameobject = static_cast<BaseComponent*>(hit.block.actor->userData)->GetGameObject();
		if (InputManager::IsKeyboardKey(InputState::pressed, 'F'))
		{
			if (const auto groundItem = gameobject->GetComponent<GroundItem>())
			{
				std::cout << "Picked up item: " << groundItem->GetItem() << "\n";
			}
			
			gameobject->GetParent()->RemoveChild(gameobject, true);
		}
	}
}
