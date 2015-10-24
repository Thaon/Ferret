#pragma once

#include"RenderSystem.h"
#include "Scenegraph.h"
#include "InputSystem.h"
#include <time.h>

class FerretGame
{
private:
	float m_lastTime = 0;
	bool isRunning;
	bool isPaused;
public:
	FerretGame();
	~FerretGame();

	float getElapsedSeconds();

	void Init();
	void GetInput();
	void Update();
	void Render();
};

