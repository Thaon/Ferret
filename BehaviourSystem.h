#pragma once

#include "BehaviourComponent.h"
#include "Scenegraph.h"

class BehaviourSystem
{
private:
	Scenegraph* sceneGraph;
public:
	BehaviourSystem();
	~BehaviourSystem();

	void Start(Scenegraph* scene, cInputMgr* theInputMgr, cFontMgr* theFontMgr, cSoundMgr* theSoundMgr);

	void Update(float deltaTime);
};

