#include "FerretGame.h"



FerretGame::FerretGame()
{

}


FerretGame::~FerretGame()
{
}

float FerretGame::getElapsedSeconds()
{
	float currentTime = float(GetTickCount()) / 1000.0f;
	float seconds = float(currentTime - m_lastTime);
	m_lastTime = currentTime;
	return seconds;
}