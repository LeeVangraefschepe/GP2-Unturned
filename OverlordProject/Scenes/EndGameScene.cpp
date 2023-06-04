#include "stdafx.h"
#include "EndGameScene.h"

#include "ScoreManager.h"


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

	m_pFont = ContentManager::Load<SpriteFont>(L"SpriteFonts/Minecraft_32.fnt");

	const auto backgroundImage = new GameObject();
	const auto spriteComp = backgroundImage->AddComponent(new SpriteComponent(L"Textures/UI/BannerGameOver.png", { 0.f,0.f }, { 1.f,1.f,1.f,1.f }));
	backgroundImage->GetTransform()->Translate(0, 0, 0.5f);
	spriteComp->SetDimensions({ m_SceneContext.windowWidth, m_SceneContext.windowHeight });
	AddChild(backgroundImage);

	constexpr XMFLOAT2 buttonSize{ 600.f * 0.7f, 150.f * 0.7f };
	m_pButtonContinue = new ButtonPrefab{ L"Textures/UI/ContinueButtonLong.png", buttonSize };
	m_pButtonContinue->GetTransform()->Translate(0.f, m_SceneContext.windowHeight / 2 - buttonSize.y / 2.f + buttonSize.y * 2.4f, 0.1f);
	AddChild(m_pButtonContinue);
}

void EndGameScene::Update()
{
	if (m_loaded == false)
	{
		if (const auto gameScene = SceneManager::Get()->GetScene(L"MapScene"))
		{
			SceneManager::Get()->RemoveGameScene(gameScene, true);
			m_loaded = true;
		}
	}
	InputManager::SetForceMouseToCenter(false);
	if (m_pButtonContinue->IsClicked())
	{
		m_loaded = false;
		SceneManager::Get()->SetActiveGameScene(SceneManager::Get()->GetScene(L"MainMenuScene"));
		ScoreManager::Get()->ResetScore();
		m_pButtonContinue->Reset();
	}
}

void EndGameScene::Draw()
{
	std::wstringstream ss{};
	ss << L"Total score";
	TextRenderer::Get()->DrawText(m_pFont, ss.str(), { 10,m_SceneContext.windowHeight / 2.f }, XMFLOAT4{ Colors::White });

	ss.str(L"");
	ss << ScoreManager::Get()->GetScore();
	TextRenderer::Get()->DrawText(m_pFont, ss.str(), { 10,m_SceneContext.windowHeight / 2.f + 40.f }, XMFLOAT4{ Colors::White });
}

void EndGameScene::OnGUI()
{
}

void EndGameScene::PostInitialize()
{
}