#pragma once

#include <time.h>
#include "cWNDManager.h"
#include"RenderSystem.h"

class FerretGame
{
private:
	float m_lastTime = 0;
	bool m_isRunning;
	bool isPaused;

	cWNDManager* window;
	Scenegraph* sceneGraph;
	cInputMgr* theInputMgr;

	RenderSystem renderSys;
	static FerretGame* pInstance;
	FerretGame* pgmWNDMgr;

	std::string m_gameTitle;

public:
	FerretGame();
	~FerretGame();

	bool isRunning();

	float GetElapsedSeconds();

	Scenegraph* GetSceneGraph() { return sceneGraph; }
	cInputMgr* Input() { return theInputMgr; }

	int Run();
	void Init(int windowWidth, int windowHeight, int BPP);

};

