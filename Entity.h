#pragma once
#include <vector>
#include <string>

#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "BehaviourComponent.h"

#include "cInputMgr.h"

class Entity
{
private:
	std::string m_name;
	TransformComponent* transformComponent;
	SpriteComponent* spriteComponent;
	BehaviourComponent* behaviourComponent;

public:
	void AddTransform() { transformComponent = new TransformComponent(); }
	TransformComponent* GetTransform() { return transformComponent; }

	void AddSprite() { spriteComponent = new SpriteComponent(); }
	SpriteComponent* GetSpriteComponent() { return spriteComponent; }

	void AddBehaviour() { behaviourComponent = new BehaviourComponent(); }
	BehaviourComponent* GetBehaviour() { return behaviourComponent; }

	void attachInputMgr(cInputMgr* inputMgr);  // Attach the Input Manager

	//getters
	std::string GetName() { return m_name; }
};