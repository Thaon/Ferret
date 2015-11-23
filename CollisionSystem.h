#pragma once

#include <vector>
#include "Collision2DComponent.h"
#include "Scenegraph.h"

class CollisionSystem
{
private:

public:
	void Update(Scenegraph* scene);

	CollisionSystem();
	~CollisionSystem();
};

