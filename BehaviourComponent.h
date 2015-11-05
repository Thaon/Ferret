#pragma once

#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "cInputMgr.h"

class BehaviourComponent
{
private:
	cInputMgr* Input;
	TransformComponent* transformComponent;
	SpriteComponent* spriteComponent;
public:
	void SetInput(cInputMgr* input) { Input = input; }
	cInputMgr* GetInput() { return Input; }
	void SetTransform(TransformComponent* value) { transformComponent = value; }
	TransformComponent* GetTransform() { return transformComponent; }
	void SetSpriteComponent(SpriteComponent* value) { spriteComponent = value; }
	SpriteComponent* GetSpriteComponent() { return spriteComponent; }
	virtual void Start() {};
	virtual void Update() {};
};