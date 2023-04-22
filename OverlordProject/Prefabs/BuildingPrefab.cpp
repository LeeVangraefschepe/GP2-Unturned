#include "stdafx.h"
#include "BuildingPrefab.h"

BuildingPrefab::BuildingPrefab(const std::wstring& path, BaseMaterial* material, const PxMaterial* physMaterial, XMFLOAT3 position, XMFLOAT3 rotation)
{
	const auto pModel2 = new ModelComponent{  path + L".ovm" };
	pModel2->SetMaterial(material);
	AddComponent(pModel2);

	const auto staticRb = AddComponent(new RigidBodyComponent{ true });
	const auto buildingConvex = ContentManager::Load<PxTriangleMesh>(path + L".ovpt");
	staticRb->AddCollider(PxTriangleMeshGeometry{ buildingConvex }, *physMaterial);

	GetTransform()->Rotate(90.f + rotation.x, 0.f + rotation.y, 0.f + rotation.z);
	GetTransform()->Translate(position);
	staticRb->GetTransform()->Rotate(90.f + rotation.x, 0.f + rotation.y, 0.f + rotation.z);
	staticRb->GetTransform()->Translate(position);
}