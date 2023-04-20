#include "stdafx.h"
#include "MainMenuScene.h"

#include "Prefabs/ButtonPrefab.h"

MainMenuScene::MainMenuScene() :
	GameScene(L"MainMenuScene") {}

void MainMenuScene::Initialize()
{
	m_SceneContext.settings.drawUserDebug = false;
	m_SceneContext.settings.drawGrid = false;
	m_SceneContext.settings.showInfoOverlay = false;
	m_SceneContext.settings.drawPhysXDebug = false;
	m_SceneContext.settings.enableOnGUI = false;
	m_SceneContext.settings.clearColor = XMFLOAT4{ 0.f,0.f,0.f,1.f };

	const auto startButton = new ButtonPrefab{ L"Textures/Banner.png", XMFLOAT2{100,100} };
	AddChild(startButton);

	m_pSprite = new GameObject();
	const auto spriteComp = m_pSprite->AddComponent(new SpriteComponent(L"Textures/Banner.png", { 0.f,0.f }, { 1.f,1.f,1.f,1.f }));
	spriteComp->SetDimensions(m_SceneContext.windowWidth, m_SceneContext.windowHeight);
	AddChild(m_pSprite);
}

void MainMenuScene::Update()
{
}

void MainMenuScene::Draw()
{
}

void MainMenuScene::OnGUI()
{
}

void MainMenuScene::PostInitialize()
{
}