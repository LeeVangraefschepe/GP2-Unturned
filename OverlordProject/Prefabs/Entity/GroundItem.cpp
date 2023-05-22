#include "stdafx.h"
#include "GroundItem.h"

#include "Materials/DiffuseMaterial.h"

GroundItem::GroundItem(const std::wstring& item, XMFLOAT3 position):
m_position(position)
{
	const auto material = MaterialManager::Get()->CreateMaterial<DiffuseMaterial>();
	material->SetDiffuseTexture(L"Textures/Items/" + item + L".png");

	const auto model = new ModelComponent{ L"Meshes/Items/" + item + L".ovm" };
	model->SetMaterial(material);
	AddComponent(model);

	const auto pMaterial = PxGetPhysics().createMaterial(.5f, .5f, .5f);
	const auto staticRb = AddComponent(new RigidBodyComponent{ true });
	const auto buildingConvex = ContentManager::Load<PxConvexMesh>(L"Meshes/Items/" + item + L".ovpc");
	staticRb->AddCollider(PxConvexMeshGeometry{ buildingConvex }, *pMaterial);
	staticRb->SetCollisionGroup(CollisionGroup::Group2);

	GetTransform()->Translate(position);
}

void GroundItem::Update(const SceneContext& sceneContext)
{
}