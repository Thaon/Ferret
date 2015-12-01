#pragma once
#include "BehaviourComponent.h"
#include "Entity.h"

class PlayerBehaviour : public BehaviourComponent
{
private:

public:
	PlayerBehaviour();
	~PlayerBehaviour();

	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void OnCollisionEnter(Entity* other);
};

