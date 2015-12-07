#pragma once
#include "BehaviourComponent.h"
#include "Entity.h"

class MenuBehaviour : public BehaviourComponent
{
public:
	MenuBehaviour();
	~MenuBehaviour();

	virtual void Start();
	virtual void Update(float deltaTime);
};

