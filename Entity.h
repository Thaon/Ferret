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
	Entity(){}
	Entity(std::string name) { m_name = name; }

	void AddTransform() { transformComponent = new TransformComponent(); }
	TransformComponent* GetTransform() { return transformComponent; }

	void AddSprite() { spriteComponent = new SpriteComponent(); }
	SpriteComponent* GetSpriteComponent() { return spriteComponent; }

	void AddBehaviour() { behaviourComponent = new BehaviourComponent(); }
	void SetBehaviour(BehaviourComponent* value) { behaviourComponent = value; }
	BehaviourComponent* GetBehaviour() { return behaviourComponent; }

	//getters
	std::string GetName() { return m_name; }
};