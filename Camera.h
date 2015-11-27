#pragma once

#include "Entity.h"
#include <glm/glm.hpp>

class Camera
{
private:
	Entity* m_entityToFollow;
	glm::vec2 m_position;
	int m_viewWidth, m_viewHeight, m_xOffset, m_yOffset;

public:

	Camera();
	~Camera();
	Camera(int width, int height);

	void Move(glm::vec2 newPosition);
	void SetEntityToFollow(Entity* entityToFollow, int xOffset, int yOffset);
	void Update(float deltaTime);
	void SetPosition(glm::vec2 position);
	glm::vec2 GetPosition();
};

