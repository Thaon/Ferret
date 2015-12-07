#include "Ball.h"

Ball::Ball()
{
}


Ball::~Ball()
{
}


void Ball::Start()
{
	//reset the game state
	SetGameState(-1);
	//set the ball in the center
	GetTransform()->SetPosition(glm::vec2(600, 360));
	//start it moving
	m_xSpeed = rand() % 100 + 150;
	m_ySpeed = rand() % 100 + 150;
	//but direct it into the player first
	m_xDir = -1;
	m_yDir = IntervalRandom(-1, 1);

	GetFontMgr()->addFont("space", "Fonts/space age.ttf", 24);

	m_previousPosition = GetTransform()->GetPosition();

	GetSoundMgr()->getSnd("boop")->playAudio(AL_TRUE);
	//GetSoundMgr()->getSnd("Game music")->playAudio(AL_FALSE);

}

float Ball::IntervalRandom(float x0, float x1) //from http://c-faq.com/lib/randrange.html
{
	return x0 + (x1 - x0) * rand() / ((float)RAND_MAX);
}

void Ball::Update(float deltaTime)
{
	m_previousPosition = GetTransform()->GetPosition();

	GetTransform()->SetPosition(m_xSpeed * m_xDir * deltaTime, m_ySpeed * m_yDir * deltaTime);

	if (GetTransform()->GetPosition().y < 60 || GetTransform()->GetPosition().y > 700) //if going out of bounds up and down
	{
		GetTransform()->SetPosition(m_previousPosition);
		m_yDir = -m_yDir;
	}
	if (GetTransform()->GetPosition().x > 1200)
	{
		m_previousPosition = GetTransform()->GetPosition(); //we get the position here cause when the game is reset the ball gets dragged back to the previous position, if not updated it will go back to beyond the player
		SetGameState(1); //point scored by player, see FerretGame.cpp
	}

	//scoring
	if (GetTransform()->GetPosition().x < -40)
	{
		m_previousPosition = GetTransform()->GetPosition();
		SetGameState(2); //point scored by AI, see FerretGame.cpp
	}

	//draw center for debug
	GetFontMgr()->getFont("space")->printText(".", FTPoint(GetSpriteComponent()->GetCenter(GetTransform()->GetPosition()).x, GetSpriteComponent()->GetCenter(GetTransform()->GetPosition()).y, 0));

}

void Ball::OnCollisionEnter(Entity* other)
{
	if (m_canChangeDir)
	{
		GetTransform()->SetPosition(m_previousPosition);

		//calculate point of impact
		//if (GetSpriteComponent()->GetCenter(GetTransform()->GetPosition()).y - (other->GetSpriteComponent()->GetCenter(GetTransform()->GetPosition()).y) < 0)

		float myY = GetSpriteComponent()->GetCenter(GetTransform()->GetPosition()).y;
		float otherY = other->GetSpriteComponent()->GetCenter(other->GetTransform()->GetPosition()).y;

		m_yDir = (myY - otherY) / 100;

		m_xDir = -m_xDir * 1.1f; //we reverse and amplify the speed
		m_canChangeDir = false;
	}
	else
	{ //a bit hacked in but it takes into account the double check for collision in the collision system (should have fixed it earlier)
		m_canChangeDir = true;
	}
}