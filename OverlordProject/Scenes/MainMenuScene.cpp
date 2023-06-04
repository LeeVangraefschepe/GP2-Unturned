#include "stdafx.h"
#include "MainMenuScene.h"

#include "MapScene.h"
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

	const auto backgroundImage = new GameObject();
	const auto spriteComp = backgroundImage->AddComponent(new SpriteComponent(L"Textures/UI/Banner.png", { 0.f,0.f }, { 1.f,1.f,1.f,1.f }));
	backgroundImage->GetTransform()->Translate(0, 0, 0.5f);
	spriteComp->SetDimensions({ m_SceneContext.windowWidth, m_SceneContext.windowHeight });
	AddChild(backgroundImage);

	m_pButtonStart = new ButtonPrefab{ L"Textures/UI/PlayButton.png", XMFLOAT2{300,100} };
	m_pButtonStart->GetTransform()->Translate(0.f, m_SceneContext.windowHeight / 4.f, 0.1f);
	AddChild(m_pButtonStart);

	m_pButtonQuit = new ButtonPrefab{ L"Textures/UI/QuitButton.png", XMFLOAT2{300,100} };
	m_pButtonQuit->GetTransform()->Translate(0.f, m_SceneContext.windowHeight / 4.f + 120, 0.1f);
	AddChild(m_pButtonQuit);

	const auto pFmod{ SoundManager::Get()->GetSystem() };
	FMOD_RESULT result = pFmod->createStream("Resources/Audio/MainMenuMusic.mp3", FMOD_2D | FMOD_LOOP_NORMAL, nullptr, &m_music);
	SoundManager::Get()->ErrorCheck(result);

	//Start playing paused
	result = pFmod->playSound(m_music, nullptr, true, &m_channel);
	SoundManager::Get()->ErrorCheck(result);

	m_channel->setVolume(0.7f);
}

void MainMenuScene::Update()
{
	if (m_loaded == false)
	{
		m_loaded = true;
	}
	m_channel->setPaused(false);

	InputManager::SetForceMouseToCenter(false);
	if (m_pButtonStart->IsClicked())
	{
		m_loaded = false;
		m_pButtonStart->Reset();
		m_channel->setPaused(true);
		SceneManager::Get()->AddGameScene(new MapScene());
		SceneManager::Get()->SetActiveGameScene(L"MapScene");
	}
	if (m_pButtonQuit->IsClicked())
	{
		m_channel->stop();
		PostQuitMessage(0);
		m_pButtonStart->Reset();
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