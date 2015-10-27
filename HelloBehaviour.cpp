#include "BehaviourComponent.h"
#include <iostream>

class HelloBehaviour : public BehaviourComponent
{
public:
	virtual void Start()
	{
		std::cout << "Hello!";
	}
};