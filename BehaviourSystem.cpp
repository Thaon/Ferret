#include "BehaviourSystem.h"



BehaviourSystem::BehaviourSystem()
{
}


BehaviourSystem::~BehaviourSystem()
{
}

void BehaviourSystem::Start(Scenegraph* scene, cInputMgr* theInputMgr, cFontMgr* theFontMgr, cSoundMgr* theSoundMgr)
{
	sceneGraph = scene;
	for each (Entity* gameObject in sceneGraph->GetEntities())
	{
		if (gameObject->GetBehaviour() != NULL)
		{
			//here in the behaviour system we initialize input, sound and font handling as well, s that every entity will be able to access them on the fly
			gameObject->GetBehaviour()->SetInput(theInputMgr);//put this in the input system instead! ...or not...
			gameObject->GetBehaviour()->SetFontMgr(theFontMgr);
			gameObject->GetBehaviour()->SetSoundMgr(theSoundMgr);
			gameObject->GetBehaviour()->SetTransform(gameObject->GetTransform());
			gameObject->GetBehaviour()->SetSpriteComponent(gameObject->GetSpriteComponent());
			gameObject->GetBehaviour()->Start();
		}
	}
}

void BehaviourSystem::Update(float deltaTime)
{
	for each (Entity* gameObject in sceneGraph->GetEntities())
	{
		if (gameObject->GetBehaviour() != NULL)
		{
			gameObject->GetBehaviour()->Update(deltaTime);
		}
	}
}
