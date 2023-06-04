#include "stdafx.h"
#include "PauseMenuScene.h"

PauseMenuScene::PauseMenuScene() : GameScene{L"PauseMenuScene"}{}

void PauseMenuScene::Initialize()
{
	m_SceneContext.settings.drawUserDebug = false;
	m_SceneContext.settings.drawGrid = false;
	m_SceneContext.settings.showInfoOverlay = false;
	m_SceneContext.settings.drawPhysXDebug = false;
	m_SceneContext.settings.enableOnGUI = false;
	m_SceneContext.settings.clearColor = XMFLOAT4{ 0.1f,0.1f,0.1f,1.f };

	constexpr XMFLOAT2 buttonSize { 600.f*0.7f, 150.f*0.7f };

	m_pButtonContinue = new ButtonPrefab{ L"Textures/UI/ContinueButtonLong.png", buttonSize };
	m_pButtonContinue->GetTransform()->Translate(0.f, m_SceneContext.windowHeight / 2 - buttonSize.y / 2.f - buttonSize.y * 1.2f, 0.f);
	AddChild(m_pButtonContinue);

	m_pButtonRestart = new ButtonPrefab{ L"Textures/UI/RestartButtonLong.png", buttonSize };
	m_pButtonRestart->GetTransform()->Translate(0.f, m_SceneContext.windowHeight/2 - buttonSize.y / 2.f, 0.f);
	AddChild(m_pButtonRestart);

	m_pButtonMainMenu = new ButtonPrefab{ L"Textures/UI/MainMenuButtonLong.png", buttonSize };
	m_pButtonMainMenu->GetTransform()->Translate(0.f, m_SceneContext.windowHeight / 2 - buttonSize.y / 2.f + buttonSize.y * 1.2f, 0.f);
	AddChild(m_pButtonMainMenu);

	m_pButtonQuit = new ButtonPrefab{ L"Textures/UI/QuitButtonLong.png", buttonSize };
	m_pButtonQuit->GetTransform()->Translate(0.f, m_SceneContext.windowHeight / 2 - buttonSize.y / 2.f + buttonSize.y * 2.4f, 0.f);
	AddChild(m_pButtonQuit);

	const auto backgroundImage = new GameObject();
	backgroundImage->GetTransform()->Translate(0, 0, 0.1f);
	const auto spriteComp = backgroundImage->AddComponent(new SpriteComponent(L"Textures/UI/BannerPauseMenu.png", { 0.f,0.f }, { 1.f,1.f,1.f,1.f }));
	spriteComp->SetDimensions({ m_SceneContext.windowWidth, m_SceneContext.windowHeight });
	AddChild(backgroundImage);
}

void PauseMenuScene::Update()
{
	InputManager::SetForceMouseToCenter(false);
	if (m_pButtonRestart->IsClicked())
	{
		std::cout << "Restart\n";
		m_pButtonQuit->Reset();
	}
}

void PauseMenuScene::Draw()
{
}

void PauseMenuScene::OnGUI()
{
}

void PauseMenuScene::PostInitialize()
{
}
