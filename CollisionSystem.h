#pragma once

#include <vector>
#include "Collision2DComponent.h"
#include "Scenegraph.h"

class CollisionSystem
{
private:
	Scenegraph* sceneGraph;
public:
	void Start(Scenegraph* scene);
	void Update();

	CollisionSystem();
	~CollisionSystem();
};

