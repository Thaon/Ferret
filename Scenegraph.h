#pragma once

#include <vector>
#include <string>
#include "Entity.h"
#include "Camera.h"

class Scenegraph
{
private:
	std::vector<Entity*> m_gameObjects;
	std::vector<Camera*> m_cameras;
	int m_size;

public:
	Scenegraph();
	~Scenegraph();

	Entity* Instantiate(Entity* entity, glm::vec2 position, float orientation);
	Camera* Instantiate(Camera* camera, glm::vec2 position);

	//getters
	Entity* Find(std::string name);
	std::vector<Entity*> GetEntities();
	std::vector<Camera*> GetCameras();
};

