#pragma once
#include "BehaviourComponent.h"
#include "Entity.h"
#include <sstream>

class PointsCounterBehaviour : public BehaviourComponent
{
private:
	int m_aiPoints, m_playerPoints;
	std::string m_aiStrPoints, m_playerStrPoints;

public:

	PointsCounterBehaviour();
	~PointsCounterBehaviour();

	void IncreaseAiPoints();
	void IncreasePlayerPoints();
	void ResetPoints();

	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void Signal(std::string signal);
};

