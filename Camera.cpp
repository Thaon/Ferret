#include "Camera.h"

Camera::Camera(int width, int height)
{
	m_position = glm::vec2(0, 0);
	m_viewWidth = width;
	m_viewHeight = height;
}

Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::Move(glm::vec2 newPosition)
{
	m_position += newPosition;
}

void Camera::SetEntityToFollow(Entity* entityToFollow, int xOffset, int yOffset)
{
	m_entityToFollow = entityToFollow;
	m_xOffset = xOffset;
	m_yOffset = yOffset;
}

void Camera::Update(float deltaTime)
{
	if (m_entityToFollow != NULL)
	{
		m_position = m_entityToFollow->GetTransform()->GetPosition() - glm::vec2(m_xOffset, m_yOffset);
	}
}

void Camera::SetPosition(glm::vec2 position)
{
	m_position = position;
}

glm::vec2 Camera::GetPosition()
{
	return m_position;
}