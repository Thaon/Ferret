#pragma once

#include <vector>
#include <string>
#include "Entity.h"

class Scenegraph
{
private:
	std::vector<Entity*> m_gameObjects;
	int m_size;

public:
	Scenegraph();
	~Scenegraph();

	Entity* Instantiate(Entity* entity, glm::vec2 position, float orientation);


	//getters
	Entity* Find(std::string name);
	std::vector<Entity*> GetEntities();
};

