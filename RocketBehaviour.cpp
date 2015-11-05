#include "BehaviourComponent.h"

class RocketBehaviour : public BehaviourComponent
{
	virtual void Start() {}

	virtual void Update()
	{
		if (GetInput()->isKeyDown(VK_RIGHT))
		{
			GetTransform()->SetRotation(1);
		}
		if (GetInput()->isKeyDown(VK_LEFT))
		{
			GetTransform()->SetRotation(-1);
		}
	}
};