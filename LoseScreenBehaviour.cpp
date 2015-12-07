#include "LoseScreenBehaviour.h"



LoseScreenBehaviour::LoseScreenBehaviour()
{
}


LoseScreenBehaviour::~LoseScreenBehaviour()
{
}

void LoseScreenBehaviour::Start()
{
	SetGameState(-1);
}

void LoseScreenBehaviour::Update(float deltaTime)
{
	if (GetInput()->getLeftMouseBtn())
	{
		if (GetInput()->getMouseXPos() > 565 && GetInput()->getMouseYPos() > 420 && GetInput()->getMouseXPos() < 715 && GetInput()->getMouseYPos() < 460) //start "button" is pressed
			SetGameState(1); //starting the game

		if (GetInput()->getMouseXPos() > 580 && GetInput()->getMouseYPos() > 500 && GetInput()->getMouseXPos() < 690 && GetInput()->getMouseYPos() < 540) //start "button" is pressed
			SetGameState(2); //ending the game
	}
}
