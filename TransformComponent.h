#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/geometric.hpp>

class TransformComponent
{
private:
	//disable copy constructor
	TransformComponent(const TransformComponent&) = delete;
	TransformComponent & operator = (TransformComponent&) = delete;

	glm::vec2 position = glm::vec2(0,0);
	float orientation = 0.0f;
	glm::vec2 scale = glm::vec2(1,1);
public:
	//constructor
	TransformComponent() = default;

	//getters
	glm::vec2 GetPosition() { return position; }
	float GetRotation() { return orientation; }
	glm::vec2 GetScale() { return scale; }
	//setters
	void SetPosition(float newX, float newY) { position.x = newX; position.y = newY; }
	void SetPosition(glm::vec2 newPosition) { position = newPosition; }
	void SetRotation(float newOrientation) { orientation = newOrientation; }
	void SetScale(float newScale) { scale = newScale; }

};