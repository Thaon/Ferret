#include "Scenegraph.h"



Scenegraph::Scenegraph()
{
	m_size = 1;
}


Scenegraph::~Scenegraph()
{
}

Entity Scenegraph::Find(std::string name)
{
	for each (Entity entity in m_gameObjects)
	{
		if (entity.GetName() == name)
			return entity;
	}
}

Entity Scenegraph::Instantiate(Entity entity, glm::vec2 position, float orientation)
{
	m_gameObjects.reserve(m_size++);
	m_gameObjects.resize(m_size++);
	m_gameObjects.push_back(entity);
	//we add the transform assuming it is going to be required by every gameobject
	//entity.AddTransform();
	//entity.GetTransform()->SetPosition(position);
	//entity.GetTransform()->SetRotation(orientation);
	return entity;
}

std::vector<Entity> Scenegraph::GetEntities()
{
	return m_gameObjects;
}