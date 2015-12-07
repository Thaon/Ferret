#include "PointsCounterBehaviour.h"


PointsCounterBehaviour::PointsCounterBehaviour()
{
}


PointsCounterBehaviour::~PointsCounterBehaviour()
{
}

void PointsCounterBehaviour::IncreaseAiPoints()
{
	m_aiPoints++;
	std::stringstream ss(std::stringstream::in | std::stringstream::out);
	ss << m_aiPoints;
	m_aiStrPoints = ss.str();

	if (m_aiPoints > 4) //game is first to 5 wins
	{
		SetGameState(1); //ai won
	}
}

void PointsCounterBehaviour::IncreasePlayerPoints()
{
	m_playerPoints++;
	std::stringstream ss(std::stringstream::in | std::stringstream::out);
	ss << m_playerPoints;
	m_playerStrPoints = ss.str();

	if (m_playerPoints > 4) //game is first to 5 wins
	{
		SetGameState(2); //player won
	}
}

void PointsCounterBehaviour::ResetPoints()
{
	SetGameState(-1);
	m_aiPoints = 0;
	m_playerPoints = 0;

	//convert int to LPCSTR
	std::stringstream ss(std::stringstream::in | std::stringstream::out);
	ss << m_aiPoints;
	m_aiStrPoints = ss.str();

	std::stringstream ss1(std::stringstream::in | std::stringstream::out);
	ss1 << m_playerPoints;
	m_playerStrPoints = ss1.str();
}

void PointsCounterBehaviour::Start()
{
	GetFontMgr()->addFont("Pong", "Fonts/Blackentina 4F.ttf", 64);
}

void PointsCounterBehaviour::Update(float deltaTime)
{
	GetFontMgr()->getFont("Pong")->printText(m_playerStrPoints.c_str(), FTPoint((1280 / 2) - 100, 50));
	GetFontMgr()->getFont("Pong")->printText(m_aiStrPoints.c_str(), FTPoint((1280 / 2) + 100, 50));
}

void PointsCounterBehaviour::Signal(std::string signal)
{
	if (signal == "Increase Ai Points")
		IncreaseAiPoints();

	if (signal == "Increase Player Points")
		IncreasePlayerPoints();
	if (signal == "Reset Points")
		ResetPoints();
}