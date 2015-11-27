#pragma once
#include <vector>
#include <string>

#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "BehaviourComponent.h"
#include "Collision2DComponent.h"

class Entity
{
private:
	std::string m_name;
	TransformComponent* transformComponent;
	SpriteComponent* spriteComponent;
	BehaviourComponent* behaviourComponent;
	Collision2DComponent* collision2DComponent;

public:
	Entity(){}
	Entity(std::string name) { m_name = name; }

	void SetName(std::string value) { m_name = value; }
	std::string GetName() { return m_name; }

	void AddTransform() { transformComponent = new TransformComponent(); }
	TransformComponent* GetTransform() { return transformComponent; }

	void AddSprite() { spriteComponent = new SpriteComponent(); }
	SpriteComponent* GetSpriteComponent() { return spriteComponent; }

	void AddBehaviour() { behaviourComponent = new BehaviourComponent(); }
	void SetBehaviour(BehaviourComponent* value) { behaviourComponent = value; }
	void RemoveBehaviour() { behaviourComponent = NULL; }
	BehaviourComponent* GetBehaviour() { return behaviourComponent; }

	void AddCollision2DComponent() { collision2DComponent = new Collision2DComponent(); }
	Collision2DComponent* GetCollision2DComponent() { return collision2DComponent; }

};