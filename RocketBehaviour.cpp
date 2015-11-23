#include "BehaviourComponent.h"

class RocketBehaviour : public BehaviourComponent
{
	virtual void Start()
	{
		GetFontMgr()->addFont("Space", "Fonts/space age.ttf", 24);
	}

	virtual void Update(float deltaTime)
	{
		if (GetInput()->isKeyDown(VK_RIGHT))
		{
			GetTransform()->SetPosition(1, 0);
		}
		if (GetInput()->isKeyDown(VK_LEFT))
		{
			GetTransform()->SetPosition(-1, 0);
		}
	}

	virtual void OnCollisionEnter(Entity* other)
	{
		GetFontMgr()->getFont("Space")->printText("Collision!", FTPoint(0.0f, -1.0f, 0.0f));
	}
};