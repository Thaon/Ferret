#include "Ball.h"

Ball::Ball()
{
}


Ball::~Ball()
{
}


void Ball::Start()
{
	//set the ball in the center
	GetTransform()->SetPosition(glm::vec2(600, 360));
	//start it moving
	m_xSpeed = rand() % 100 + 150;
	m_ySpeed = rand() % 100 + 150;
	//but direct it into the player first
	m_xDir = -1;
	m_yDir = (int)IntervalRandom(-1, 1);

	GetFontMgr()->addFont("space", "Fonts/space age.ttf", 24);

	m_previousPosition = GetTransform()->GetPosition();

}

float Ball::IntervalRandom(float x0, float x1) //from http://c-faq.com/lib/randrange.html
{
	return x0 + (x1 - x0) * rand() / ((float)RAND_MAX);
}

void Ball::Update(float deltaTime)
{
	m_previousPosition = GetTransform()->GetPosition();

	GetTransform()->SetPosition(m_xSpeed * m_xDir * deltaTime, m_ySpeed * m_yDir * deltaTime);

	if (GetTransform()->GetPosition().y < 40 || GetTransform()->GetPosition().y > 700)
	{
		GetTransform()->SetPosition(m_previousPosition);
		m_yDir = -m_yDir;
	}
	if (GetTransform()->GetPosition().x > 1200)
	{
		GetTransform()->SetPosition(m_previousPosition);
		m_xDir = -m_xDir;
	}

	//scoring
	if (GetTransform()->GetPosition().x < -40)
	{
		m_previousPosition = GetTransform()->GetPosition();
		SetGameState(2);
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
		m_yDir = (GetSpriteComponent()->GetCenter(GetTransform()->GetPosition()).y - other->GetSpriteComponent()->GetCenter(GetTransform()->GetPosition()).y) / 100;

		m_xDir = -m_xDir * 1.1f; //we reverse and amplify the speed
		m_canChangeDir = false;
	}
	else
	{ //a bit hacked in but it takes into account the double check for collision in the collision system (should have fixed it earlier)
		m_canChangeDir = true;
	}
}