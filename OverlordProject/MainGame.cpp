#include "stdafx.h"
#include "MainGame.h"

#include "Scenes/EndGameScene.h"
#include "Scenes/MainMenuScene.h"
#include "Scenes/MapScene.h"
#include "Scenes/PauseMenuScene.h"

//Game is preparing
void MainGame::OnGamePreparing(GameContext& gameContext)
{
	//Here you can change some game settings before engine initialize
	//gameContext.windowWidth=... (default is 1280)
	//gameContext.windowHeight=... (default is 720)
	gameContext.windowTitle = L"Unturned";
	gameContext.fullScreen = false;
	m_gameContext = &gameContext;
}

void MainGame::Initialize()
{
	SceneManager::Get()->AddGameScene(new MainMenuScene());
	SceneManager::Get()->AddGameScene(new PauseMenuScene());
	SceneManager::Get()->AddGameScene(new EndGameScene());
}

LRESULT MainGame::WindowProcedureHook(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	if(message == WM_KEYUP)
	{
		if ((lParam & 0x80000000) != 0x80000000)
			return -1;

		//[F1] Toggle Scene Info Overlay
		if(wParam == VK_F1)
		{
			const auto pScene = SceneManager::Get()->GetActiveScene();
			pScene->GetSceneSettings().Toggle_ShowInfoOverlay();
		}

		//[F2] Toggle Debug Renderer (Global)
		if (wParam == VK_F2)
		{
			DebugRenderer::ToggleDebugRenderer();
			return 0;

		}

		//[F3] Previous Scene
		if (wParam == VK_F3)
		{
			//SceneManager::Get()->PreviousScene();
			return 0;

		}

		//[F4] Next Scene
		if (wParam == VK_F4)
		{
			//SceneManager::Get()->NextScene();
			return 0;
		}

		//[F5] If PhysX Framestepping is enables > Next Frame	
		if (wParam == VK_F6)
		{
			const auto pScene = SceneManager::Get()->GetActiveScene();
			pScene->GetPhysxProxy()->NextPhysXFrame();
		}

		if (wParam == VK_F11)
		{
			m_gameContext->fullScreen = !m_gameContext->fullScreen;
			if (m_gameContext->fullScreen)
			{
				// Remove title bar and borders
				SetWindowLongPtr(hWnd, GWL_STYLE, WS_POPUP);

				// Set window position and size to cover entire screen
				SetWindowPos(hWnd, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);
			}
			else
			{
				// Restore title bar and borders
				SetWindowLongPtr(hWnd, GWL_STYLE, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX);

				// Calculate dimensions of window based on specified width and height
				RECT r = { 0, 0, LONG(m_gameContext->windowWidth), LONG(m_gameContext->windowHeight) };
				AdjustWindowRect(&r, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, false);
				const auto winWidth = r.right - r.left;
				const auto winHeight = r.bottom - r.top;

				// Calculate position of window to center on screen
				const int x = (GetSystemMetrics(SM_CXSCREEN) - winWidth) / 2;
				const int y = (GetSystemMetrics(SM_CYSCREEN) - winHeight) / 2;

				// Set window position and size
				SetWindowPos(hWnd, HWND_TOP, x, y, winWidth, winHeight, SWP_SHOWWINDOW);
			}
		}
	}
	

	return -1;
}
