#pragma once

#include "cInputMgr.h"

#include <Windows.h>

class InputSystem
{
private:
	cInputMgr* theInputMgr;
public:
	InputSystem();
	~InputSystem();

	void Init();
};

