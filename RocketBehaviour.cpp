#include "BehaviourComponent.h"
#include "Entity.h"

class RocketBehaviour : public BehaviourComponent
{
	glm::vec2 previousPosition;

	virtual void Start()
	{
		GetFontMgr()->addFont("Space", "Fonts/space age.ttf", 24);
		GetSoundMgr()->add("boop", "Audio/explosion2.wav");
		//GetSoundMgr()->getSnd("boop")->loadWAVFile("Audio/explosion2.wav");
		//GetSoundMgr()->getSnd("boop")->playAudio(AL_FALSE);

		
	}

	virtual void Update(float deltaTime)
	{
		previousPosition = GetTransform()->GetPosition();
		if (GetInput()->isKeyDown(VK_RIGHT))
		{
			GetTransform()->SetPosition(1, 0);

		}
		if (GetInput()->isKeyDown(VK_LEFT))
		{
			GetTransform()->SetPosition(-1, 0);
		}
		if (GetInput()->isKeyDown(VK_UP))
		{
			GetTransform()->SetPosition(0, -1);

		}
		if (GetInput()->isKeyDown(VK_DOWN))
		{
			GetTransform()->SetPosition(0, 1);
		}
	}

	virtual void OnCollisionEnter(Entity* other)
	{
		if (other->GetName() == "Wall")
		{
			//GetFontMgr()->getFont("Space")->printText("Wall!", FTPoint(GetTransform()->GetPosition().x, GetTransform()->GetPosition().y, 1.0f));
			GetTransform()->SetPosition(previousPosition);
		}
		if (other->GetName() == "test2")
		{
			GetFontMgr()->getFont("Space")->printText("Rocket!", FTPoint(GetTransform()->GetPosition().x, GetTransform()->GetPosition().y, 1.0f));
			//GetSoundMgr()->getSnd("boop")->playAudio(AL_FALSE);
		}
		//GetTransform()->SetPosition(previousPosition);
		//GetFontMgr()->getFont("Space")->printText("Collision! YEEEEEEEEEEEEEEEEEEEEEE", FTPoint(GetTransform()->GetPosition().x, GetTransform()->GetPosition().y, 1.0f));
		//GetSoundMgr()->getSnd("Shot")->playAudio(AL_TRUE);
		//GetSoundMgr()->getSnd("boop")->playAudio(AL_FALSE);
	}
};