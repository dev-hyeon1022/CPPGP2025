#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include "MenuState.h"
#include "PlayState.h"
#include "CPPGP2025.h"

#pragma comment(lib, "winmm.lib")

void MenuState::Enter(HWND hWnd)
{
	std::cout << "Enter MenuState" << std::endl;
}

void MenuState::Exit()
{
	std::cout << "Exit MenuState" << std::endl;
}

void MenuState::Update(float elapsedTime)
{

}

void MenuState::Render(HDC hdc)
{

}

void MenuState::OnKeyDown(WPARAM wParam)
{
	if (wParam == VK_RETURN)
	{
		std::cout << "Go to PlayState" << std::endl;
		ChangeState(new PlayState());
	}
}

void MenuState::OnKeyUp(WPARAM wParam)
{
}

void MenuState::OnMouseDown(int x, int y, int button)
{
}

void MenuState::OnMouseUp(int x, int y, int button)
{
}

void MenuState::OnMouseMove(int x, int y)
{
}
