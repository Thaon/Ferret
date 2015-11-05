#pragma once

#include <ctime>
#include "Scenegraph.h"

class RenderSystem
{
public:
	void RenderSprite(Entity* entity);
	void Render(Scenegraph* sceneGraph);

	RenderSystem* getInstance();


	RenderSystem();
	~RenderSystem();

private:
	RenderSystem* pInstance;

	//don't need a reference to the scenegraph as it will be passed to the render method by the FerretGame class
};

