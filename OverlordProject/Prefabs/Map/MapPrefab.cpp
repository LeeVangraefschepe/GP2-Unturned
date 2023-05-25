#include "stdafx.h"
#include "MapPrefab.h"

#include "BuildingPrefab.h"
#include "Materials/Shadow/DiffuseMaterial_Shadow.h"
#include "Parser/WorldParser.h"
#include "Components/Item/GroundItem.h"

MapPrefab::MapPrefab()
{
	auto& pPhysx = PxGetPhysics();
	const auto pDefaultMaterial = pPhysx.createMaterial(0.5f, 0.5f, 0.5f);

	LoadRoad(pDefaultMaterial);
	LoadHouses(pDefaultMaterial);
	LoadItemSpawns();

	CreateGroundPlane(pDefaultMaterial, XMFLOAT3{ 0.f,-0.5f,0.f });
}

void MapPrefab::CreateGroundPlane(const PxMaterial* physMaterial, const XMFLOAT3& position)
{
	const auto pGroundMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
	pGroundMaterial->SetDiffuseTexture(L"Textures/Ground.png");

	const auto groundPlane = new GameObject{};

	const auto pModel2 = new ModelComponent{L"Meshes/GroundPlane.ovm" };
	pModel2->SetMaterial(pGroundMaterial);
	groundPlane->AddComponent(pModel2);

	const auto staticRb = groundPlane->AddComponent(new RigidBodyComponent{ true });
	const auto buildingConvex = ContentManager::Load<PxTriangleMesh>(L"Meshes/GroundPlane.ovpt");
	staticRb->AddCollider(PxTriangleMeshGeometry{ buildingConvex }, *physMaterial);

	groundPlane->GetTransform()->Translate(position);
	staticRb->GetTransform()->Translate(position);

	AddChild(groundPlane);
}

void MapPrefab::LoadRoad(const PxMaterial* physMaterial)
{
	const auto pRoadMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
	pRoadMaterial->SetDiffuseTexture(L"Textures/Road.png");

	const std::wstring straightRoadPath{ L"Meshes/Roads/Model_0" };
	const std::wstring intersectionRoadPath{ L"Meshes/Roads/Model_1" };

	constexpr WorldParser worldParser{};
	const auto roads = worldParser.RoadLoader(L"Resources/Maps/0/Road.data");
	for (auto& road : roads)
	{
		AddChild(new BuildingPrefab{ L"Meshes/Roads/" + road.name, pRoadMaterial, physMaterial, XMFLOAT3{road.x,road.y,road.z}, XMFLOAT3{0,road.rotation,0} });
	}
}

void MapPrefab::LoadHouses(const PxMaterial* physMaterial)
{
	const auto ppMillitaryMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
	ppMillitaryMaterial->SetDiffuseTexture(L"Textures/MillitaryBuilding.png");

	const auto ppFireMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
	ppFireMaterial->SetDiffuseTexture(L"Textures/FireBuilding.png");


	constexpr int amountOfBuildingMaterials{ 3 };
	std::vector<DiffuseMaterial_Shadow*> averageBuildingMaterial{};
	averageBuildingMaterial.reserve(amountOfBuildingMaterials);

	for (int i{}; i < amountOfBuildingMaterials; ++i)
	{
		auto tempMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
		std::wstringstream ss{};
		ss << "Textures/Buildings/" << i << L".png";
		tempMaterial->SetDiffuseTexture(ss.str());
		averageBuildingMaterial.push_back(tempMaterial);
	}

	constexpr WorldParser worldParser{};
	const auto houses = worldParser.HouseLoader(L"Resources/Maps/0/House.data");
	for (auto& house : houses)
	{
		auto material = ppMillitaryMaterial;
		if (house.name == L"Model_2")
		{
			material = ppFireMaterial;
		}
		else if (house.name == L"Model_0")
		{
			material = averageBuildingMaterial[rand() % amountOfBuildingMaterials];
		}
		AddChild(new BuildingPrefab{ L"Meshes/Buildings/" + house.name, material, physMaterial, XMFLOAT3{house.x,house.y,house.z}, XMFLOAT3{0,house.rotation,0} });
	}
}

void MapPrefab::LoadItemSpawns()
{
	const auto pistolMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
	pistolMaterial->SetDiffuseTexture(L"Textures/MillitaryBuilding.png");

	constexpr WorldParser worldParser{};
	const auto items = worldParser.ItemSpawnLoader(L"Resources/Maps/0/Items.data");
	for (auto& item : items)
	{
		AddChild(new GameObject{})->AddComponent(new GroundItem{ item.name, XMFLOAT3{item.x, item.y, item.z } });
	}
}
