#pragma once

#include <Windows.h>
#include <glm/glm.hpp>

class Collision2DComponent
{
private:
	//disable copy constructor
	Collision2DComponent(const Collision2DComponent&) = delete;
	Collision2DComponent & operator = (Collision2DComponent&) = delete;

	RECT* m_bounds;

public:

	Collision2DComponent() {}
	~Collision2DComponent() {}

	//getters
	RECT* GetBoundingBox() { return m_bounds; }

	//setters
	void SetBoundingBox(glm::vec2 position, int width, int height)
	{
		m_bounds->left = position.x;
		m_bounds->top = position.y;
		m_bounds->right = position.x + width;
		m_bounds->bottom = position.y + height;
	}
};
