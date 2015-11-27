#include "BehaviourComponent.h"

class RocketBehaviour : public BehaviourComponent
{
	virtual void Start()
	{
		GetFontMgr()->addFont("Space", "Fonts/space age.ttf", 24);
		GetSoundMgr()->add("boop", "Audio/explosion2.wav");
		//GetSoundMgr()->getSnd("boop")->loadWAVFile("Audio/explosion2.wav");
		GetSoundMgr()->getSnd("boop")->playAudio(AL_FALSE);

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
		GetFontMgr()->getFont("Space")->printText("Collision! YEEEEEEEEEEEEEEEEEEEEEE", FTPoint(GetTransform()->GetPosition().x, GetTransform()->GetPosition().y, 1.0f));
		//GetSoundMgr()->getSnd("Shot")->playAudio(AL_TRUE);
		GetSoundMgr()->getSnd("boop")->playAudio(AL_FALSE);
	}
};