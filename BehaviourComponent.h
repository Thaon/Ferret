#pragma once

#include "TransformComponent.h"
#include "SpriteComponent.h"

#include "cInputMgr.h"
#include "cFontMgr.h"

//class cSoundMgr;
class Entity;

class BehaviourComponent
{
private:
	cInputMgr* m_input;
	cFontMgr* m_text;
	cSoundMgr* m_audio;

	TransformComponent* transformComponent;
	SpriteComponent* spriteComponent;
public:
	void SetInput(cInputMgr* input) { m_input = input; }
	cInputMgr* GetInput() { return m_input; }

	void SetFontMgr(cFontMgr* value) { m_text = value; }
	cFontMgr* GetFontMgr() { return m_text; }

	void SetSoundMgr(cSoundMgr* value) { m_audio = value; }
	cSoundMgr* GetSoundMgr() { return m_audio; }

	void SetTransform(TransformComponent* value) { transformComponent = value; }
	TransformComponent* GetTransform() { return transformComponent; }

	void SetSpriteComponent(SpriteComponent* value) { spriteComponent = value; }
	SpriteComponent* GetSpriteComponent() { return spriteComponent; }

	virtual void OnCollisionEnter(Entity* other) {}
	virtual void OnCollisionExit() {}

	virtual void Start() {};
	virtual void Update(float deltaTime) {};
};