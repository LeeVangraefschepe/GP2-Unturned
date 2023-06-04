#include "stdafx.h"
#include "EndGameScene.h"


EndGameScene::EndGameScene() : GameScene{L"EndGameScene"}
{
}

void EndGameScene::Initialize()
{
	m_SceneContext.settings.drawUserDebug = false;
	m_SceneContext.settings.drawGrid = false;
	m_SceneContext.settings.showInfoOverlay = false;
	m_SceneContext.settings.drawPhysXDebug = false;
	m_SceneContext.settings.enableOnGUI = false;
	m_SceneContext.settings.clearColor = XMFLOAT4{ 0.1f,0.1f,0.1f,1.f };

	const auto backgroundImage = new GameObject();
	const auto spriteComp = backgroundImage->AddComponent(new SpriteComponent(L"Textures/UI/BannerGameOver.png", { 0.f,0.f }, { 1.f,1.f,1.f,1.f }));
	backgroundImage->GetTransform()->Translate(0, 0, 0.5f);
	spriteComp->SetDimensions({ m_SceneContext.windowWidth, m_SceneContext.windowHeight });
	AddChild(backgroundImage);
}

void EndGameScene::Update()
{
	
}

void EndGameScene::Draw()
{
}

void EndGameScene::OnGUI()
{
}

void EndGameScene::PostInitialize()
{
}