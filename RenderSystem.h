#pragma once

#include <ctime>
#include "Scenegraph.h"
#include "cFontMgr.h"
#include "Camera.h"

class RenderSystem
{
public:
	void SetColor(float r, float g, float b);

	void RenderSprite(Entity* entity, Camera* camera);
	void Render(Scenegraph* sceneGraph);

	//void RenderFont(FTFont* font, LPCSTR text, FTPoint textPos);

	RenderSystem();
	~RenderSystem();

private:
	//don't need a reference to the scenegraph as it will be passed to the render method by the FerretGame class
};

