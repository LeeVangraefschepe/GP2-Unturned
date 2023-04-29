#include "stdafx.h"
#include "MapPrefab.h"

#include "Materials/DiffuseMaterial.h"
#include "Materials/Shadow/DiffuseMaterial_Shadow.h"
#include "Prefabs/BuildingPrefab.h"
#include "Prefabs/CubePrefab.h"

MapPrefab::MapPrefab()
{
	auto& pPhysx = PxGetPhysics();
	const auto pDefaultMaterial = pPhysx.createMaterial(0.5f, 0.5f, 0.5f);

	//Materials
	const auto ppMillitaryMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
	ppMillitaryMaterial->SetDiffuseTexture(L"Textures/MillitaryBuilding.png");
	const auto pRoadMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
	pRoadMaterial->SetDiffuseTexture(L"Textures/Road.png");


	//Create simple building
	AddChild(new BuildingPrefab{ L"Meshes/Buildings/Model_0", ppMillitaryMaterial, pDefaultMaterial, XMFLOAT3{20,0,0}, XMFLOAT3{} });
	//AddChild(new BuildingPrefab{ L"Meshes/Buildings/Model_1", ppMillitaryMaterial, pDefaultMaterial, XMFLOAT3{20,0,0}, XMFLOAT3{} });
	//AddChild(new BuildingPrefab{ L"Meshes/Buildings/Model_2", ppMillitaryMaterial, pDefaultMaterial, XMFLOAT3{-20,0,0}, XMFLOAT3{} });
	//AddChild(new BuildingPrefab{ L"Meshes/Buildings/Model_3", ppMillitaryMaterial, pDefaultMaterial, XMFLOAT3{-40,0,0}, XMFLOAT3{} });

	//Create road
	AddChild(new BuildingPrefab{ L"Meshes/Roads/Model_0", pRoadMaterial, pDefaultMaterial, XMFLOAT3{}, XMFLOAT3{} });
	AddChild(new BuildingPrefab{ L"Meshes/Roads/Model_1", pRoadMaterial, pDefaultMaterial, XMFLOAT3{0.f, 0.f, 24.f}, XMFLOAT3{} });
	AddChild(new BuildingPrefab{ L"Meshes/Roads/Model_0", pRoadMaterial, pDefaultMaterial, XMFLOAT3{24.f,0.f,24.f}, XMFLOAT3{0,90,0} });
	AddChild(new BuildingPrefab{ L"Meshes/Roads/Model_0", pRoadMaterial, pDefaultMaterial, XMFLOAT3{-24.f,0.f,24.f}, XMFLOAT3{0,90,0} });
	AddChild(new BuildingPrefab{ L"Meshes/Roads/Model_0", pRoadMaterial, pDefaultMaterial, XMFLOAT3{-48.f,0.f,24.f}, XMFLOAT3{0,90,0} });
	CreateGroundPlane(pDefaultMaterial, XMFLOAT3{ 100,1,100 });
}

void MapPrefab::CreateGroundPlane(const PxMaterial* material, const XMFLOAT3& size)
{
	const auto groundPlane = new CubePrefab{ size.x,size.y,size.z, XMFLOAT4{Colors::Green} };
	const auto staticRb = groundPlane->AddComponent(new RigidBodyComponent{ true });

	staticRb->AddCollider(PxBoxGeometry{ size.x / 2.f, size.y / 2.f, size.z / 2.f }, *material);
	groundPlane->GetTransform()->Translate(0.f, -1.f, 0.f);
	staticRb->GetTransform()->Translate(0,-1, 0);
	AddChild(groundPlane);
}
