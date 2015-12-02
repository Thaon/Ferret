#pragma once
#include "BehaviourComponent.h"
#include "Entity.h"

class AIBehaviour : public BehaviourComponent
{
public:
	AIBehaviour();
	~AIBehaviour();

	Entity* m_ball;
};

