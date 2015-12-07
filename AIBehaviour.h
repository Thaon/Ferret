#pragma once
#include "BehaviourComponent.h"
#include "Entity.h"

class AIBehaviour : public BehaviourComponent
{
private:
	float m_speed = 100;
public:
	AIBehaviour();
	~AIBehaviour();

	Entity* m_ball;

	virtual void Start();
	virtual void Update(float deltaTime);
};

