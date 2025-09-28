#pragma once
#include "GameState.h"

class MenuState : public GameState
{
public:
	virtual void Enter(HWND hWnd);
	virtual void Exit();
	virtual void Update(float elapsedTime);
	virtual void Render(HDC hdc);

	virtual void OnKeyDown(WPARAM wParam);
	virtual void OnKeyUp(WPARAM wParam);
	virtual void OnMouseDown(int x, int y, int button);
	virtual void OnMouseUp(int x, int y, int button);
	virtual void OnMouseMove(int x, int y);
};

