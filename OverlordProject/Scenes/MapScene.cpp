#include "stdafx.h"
#include "MapScene.h"

#include "Materials/ColorMaterial.h"
#include "Materials/DiffuseMaterial.h"
#include "Prefabs/BuildingPrefab.h"

MapScene::MapScene() :
	GameScene(L"MapScene") {}

void MapScene::Initialize()
{
	auto& pPhysx = PxGetPhysics();
	const auto pBouncyMat = pPhysx.createMaterial(.5f, .5f, 1.f);
	GameSceneExt::CreatePhysXGroundPlane(*this, pBouncyMat);

	ColorMaterial* pMaterial = MaterialManager::Get()->CreateMaterial<ColorMaterial>();
	pMaterial->SetVariable_Vector(L"gColor", XMFLOAT4{ Colors::Green });

	AddChild(new BuildingPrefab{ L"Meshes/Buildings/Model_0", pMaterial, pBouncyMat, XMFLOAT3{}, XMFLOAT3{} });
}

void MapScene::Update()
{
}

void MapScene::Draw()
{
}

void MapScene::OnGUI()
{
}

void MapScene::PostInitialize()
{
}