#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#define GLX_GLXEXT_LEGACY //Must be declared so that our local glxext.h is picked up, rather than the system one

#include "FerretGame.h"

#include "RocketBehaviour.cpp"

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR cmdLine,
	int cmdShow)
{

	//Set our window settings
	const int windowWidth = 1024;
	const int windowHeight = 768;
	const int windowBPP = 16;

	FerretGame game;
	game.Init(windowWidth, windowHeight, windowBPP);

	Entity test("test");
	test.AddTransform();
	test.AddSprite();
	test.GetSpriteComponent()->SetSprite("Images\\rocketSprite.png");
	test.AddBehaviour();
	test.SetBehaviour(new RocketBehaviour);

	game.GetSceneGraph()->Instantiate(&test, glm::vec2(100, 100), 0);

	game.Run();

	return 0; //Return success
}

//to do:
//behaviour system (update(deltatime))
//input system (implement new OnKeyPressed etc..)