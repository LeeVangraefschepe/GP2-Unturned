#include "stdafx.h"
#include "GroundItem.h"

#include "Materials/DiffuseMaterial.h"

Item GroundItem::ParseString(const std::wstring& item)
{
	static std::map<std::wstring, Item> enumMap =
	{
		{L"Pistol", pistol}
	};

	if (const auto it = enumMap.find(item); it != enumMap.end())
	{
		return it->second;
	}

	throw std::runtime_error("Invalid enum value");
}

GroundItem::GroundItem(const std::wstring& item, XMFLOAT3 position):
m_name(item),
m_position(position)
{
	m_itemId = ParseString(item);
}

void GroundItem::Initialize(const SceneContext&)
{
	std::wstringstream ss{};
	const auto material = MaterialManager::Get()->CreateMaterial<DiffuseMaterial>();
	ss << L"Textures/Items/" << m_name << L".dds";
	material->SetDiffuseTexture(ss.str());
	ss.str(L"");

	ss << L"Meshes/Items/" << m_name << L".ovm";
	const auto model = new ModelComponent{ ss.str() };
	ss.str(L"");
	model->SetMaterial(material);
	GetGameObject()->AddComponent(model);

	const auto pMaterial = PxGetPhysics().createMaterial(.5f, .5f, .5f);
	const auto staticRb = GetGameObject()->AddComponent(new RigidBodyComponent{ true });
	ss << L"Meshes/Items/" << m_name << L".ovpc";
	const auto buildingConvex = ContentManager::Load<PxConvexMesh>(ss.str());
	staticRb->AddCollider(PxConvexMeshGeometry{ buildingConvex }, *pMaterial);
	staticRb->SetCollisionGroup(CollisionGroup::Group2);

	GetTransform()->Translate(m_position);
}
