#pragma once
#include "BehaviourComponent.h"
#include "Entity.h"

class Ball : public BehaviourComponent
{
private:
	float m_xSpeed, m_ySpeed;
	int m_xDir, m_yDir;
	glm::vec2 m_previousPosition;
	bool m_canChangeDir = true;
public:
	Ball();
	~Ball();

	float IntervalRandom(float x0, float x1);

	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void OnCollisionEnter(Entity* other);
};

