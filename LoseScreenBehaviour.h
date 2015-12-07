#pragma once
#include "BehaviourComponent.h"
#include "Entity.h"

class LoseScreenBehaviour : public BehaviourComponent
{
public:
	LoseScreenBehaviour();
	~LoseScreenBehaviour();

	virtual void Start();
	virtual void Update(float deltaTime);
};
