#include "AIBehaviour.h"



AIBehaviour::AIBehaviour()
{
}


AIBehaviour::~AIBehaviour()
{
}

void AIBehaviour::Start()
{
	//reset the transform on creation
	GetTransform()->SetPosition(glm::vec2(1190, 320));
}
void AIBehaviour::Update(float deltaTime)
{
	float ballY = m_ball->GetSpriteComponent()->GetCenter(m_ball->GetTransform()->GetPosition()).y;
	float myY = GetSpriteComponent()->GetCenter(GetTransform()->GetPosition()).y;

	if (myY < ballY) //if the ball is below the paddle
	{
		if (GetTransform()->GetPosition().y < 575) //if there is enough space to move down
		{
			GetTransform()->SetPosition(0, m_speed * deltaTime);
		}
	}
	else //if the ball is above
	{
		if (GetTransform()->GetPosition().y > 40) //if there is enough space to move up
		{
			GetTransform()->SetPosition(0, -m_speed * deltaTime);
		}
	}
}

//no Oncollision since the ball takes care of it all