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
	std::vector<Scenegraph*> sceneGraph;
	cInputMgr* theInputMgr;
	cFontMgr* fontMgr;
	cSoundMgr* audioMgr;
	BehaviourSystem* behaviourSys;
	RenderSystem* renderSys;
	CollisionSystem* collisionSys;
	static FerretGame* pInstance;
	FerretGame* pgmWNDMgr;

	std::string m_gameTitle;

	int m_activeScene;

public:
	FerretGame();
	~FerretGame();

	bool isRunning();
	void ChangeScene(int activeScene);

	float GetElapsedSeconds();

	Scenegraph* GetSceneGraph(int scene) { return sceneGraph[scene]; }
	void CreateSceneGraph() { sceneGraph.push_back(new Scenegraph); }
	cInputMgr* Input() { return theInputMgr; }
	cFontMgr* Text() { return fontMgr; }
	cSoundMgr* Audio() { return audioMgr; }

	int Run(int activeScene);
	void Init(int windowWidth, int windowHeight, int BPP);

};

