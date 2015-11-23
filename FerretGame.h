#pragma once

#include <time.h>
#include "cWNDManager.h"
#include"RenderSystem.h"
#include "BehaviourSystem.h"
#include "CollisionSystem.h"
#include "cSoundMgr.h"

class FerretGame
{
private:
	float m_lastTime = 0;
	bool m_isRunning;
	bool isPaused;
	float deltaTime;

	cWNDManager* window;
	Scenegraph* sceneGraph;
	cInputMgr* theInputMgr;
	cFontMgr* fontMgr;
	cSoundMgr* audioMgr;
	BehaviourSystem* behaviourSys;
	RenderSystem* renderSys;
	CollisionSystem* collisionSys;
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
	cFontMgr* Text() { return fontMgr; }
	cSoundMgr* Audio() { return audioMgr; }

	int Run();
	void Init(int windowWidth, int windowHeight, int BPP);

};

