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
	game.CreateSceneGraph();// we create our scenegraph 0 and 1 here
	game.CreateSceneGraph();

	//declare our entities here
	Entity test("test");
	test.AddTransform();
	test.AddSprite();
	test.GetSpriteComponent()->SetSprite("Images\\rocketSprite.png");
	test.AddCollision2DComponent();
	test.AddBehaviour();
	test.SetBehaviour(new RocketBehaviour);

	Entity test2("test2");
	test2.AddTransform();
	test2.AddSprite();
	test2.GetSpriteComponent()->SetSprite("Images\\rocketSprite.png");
	test2.AddCollision2DComponent();

	//create a camera for the game
	Camera camera(windowWidth, windowHeight);
	camera.SetEntityToFollow(&test, windowWidth/2, windowHeight/2);

	//instantiate them here
	game.GetSceneGraph(0)->Instantiate(&test, glm::vec2(500, 200), 0);
	game.GetSceneGraph(0)->Instantiate(&test2, glm::vec2(600, 200), 0);

	//instantiate the camera here
	game.GetSceneGraph(0)->Instantiate(&camera, glm::vec2(0, 0));

	game.Run(0);

	return 0; //Return success
}

//to do:
//behaviour system (update(deltatime))
//input system (implement new OnKeyPressed etc..)