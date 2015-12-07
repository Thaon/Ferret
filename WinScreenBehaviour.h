#pragma once
#include "BehaviourComponent.h"
#include "Entity.h"

class WinScreenBehaviour : public BehaviourComponent
{
public:
	WinScreenBehaviour();
	~WinScreenBehaviour();

	virtual void Start();
	virtual void Update(float deltaTime);
};

