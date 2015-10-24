#pragma once

#include <Windows.h>

class InputSystem
{
public:
	InputSystem();
	~InputSystem();

	LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

