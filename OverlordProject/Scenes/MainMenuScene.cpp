#include "stdafx.h"
#include "MainMenuScene.h"

#include "Prefabs/UI/ButtonPrefab.h"

MainMenuScene::MainMenuScene() :
	GameScene(L"MainMenuScene") {}

void MainMenuScene::Initialize()
{
	m_SceneContext.settings.drawUserDebug = false;
	m_SceneContext.settings.drawGrid = false;
	m_SceneContext.settings.showInfoOverlay = false;
	m_SceneContext.settings.drawPhysXDebug = false;
	m_SceneContext.settings.enableOnGUI = false;
	m_SceneContext.settings.clearColor = XMFLOAT4{ 0.1f,0.1f,0.1f,1.f };

	m_pButtonStart = new ButtonPrefab{ L"Textures/UI/PlayButton.png", XMFLOAT2{300,100} };
	m_pButtonStart->GetTransform()->Translate(0.f, m_SceneContext.windowHeight / 4.f, 0.f);
	AddChild(m_pButtonStart);

	const auto backgroundImage = new GameObject();
	const auto spriteComp = backgroundImage->AddComponent(new SpriteComponent(L"Textures/UI/Banner.png", { 0.f,0.f }, { 1.f,1.f,1.f,1.f }));
	spriteComp->SetDimensions({ m_SceneContext.windowWidth, m_SceneContext.windowHeight });
	AddChild(backgroundImage);
}

void MainMenuScene::Update()
{
	InputManager::SetForceMouseToCenter(false);
	if (m_pButtonStart->IsClicked())
	{
		m_pButtonStart->Reset();
		SceneManager::Get()->SetActiveGameScene(L"MapScene");
	}
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