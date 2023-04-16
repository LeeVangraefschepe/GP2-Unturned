#include "stdafx.h"
#include "MainMenuScene.h"

MainMenuScene::MainMenuScene() :
	GameScene(L"MainMenuScene") {}

void MainMenuScene::Initialize()
{
	m_SceneContext.settings.drawUserDebug = false;
	m_SceneContext.settings.drawGrid = false;
	m_SceneContext.settings.drawPhysXDebug = false;
	m_SceneContext.settings.enableOnGUI = true;
	m_SceneContext.settings.clearColor = XMFLOAT4{ 0.f,0.f,0.f,1.f };

	m_pSprite = new GameObject();
	const auto spriteComp = m_pSprite->AddComponent(new SpriteComponent(L"Textures/Banner.png", { 0.f,0.f }, { 1.f,1.f,1.f,1.f }));
	spriteComp->SetDimensions(m_SceneContext.windowWidth, m_SceneContext.windowHeight);

	AddChild(m_pSprite);
}

void MainMenuScene::Update()
{
	m_pSprite->GetTransform()->Rotate(0.f, 0.f, m_TotalRotation);
}

void MainMenuScene::Draw()
{
}

void MainMenuScene::OnGUI()
{
	const auto pSpriteComponent = m_pSprite->GetComponent<SpriteComponent>();

	ImGui::SliderFloat2("Position", ConvertUtil::ToImFloatPtr(pSpriteComponent->GetTransform()->GetPosition()), 0, m_SceneContext.windowWidth);
	ImGui::SliderFloat2("Scale", ConvertUtil::ToImFloatPtr(pSpriteComponent->GetTransform()->GetScale()), 0, 3);
	ImGui::SliderFloat2("Pivot", ConvertUtil::ToImFloatPtr(pSpriteComponent->GetPivot()), 0, 1);
	ImGui::ColorEdit4("Color", ConvertUtil::ToImFloatPtr(pSpriteComponent->GetColor()));

	ImGui::SliderFloat("Rotation", &m_TotalRotation, 0, 360);
}

void MainMenuScene::PostInitialize()
{
}