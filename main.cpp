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
	Entity player("Player");
	player.AddTransform();
	player.AddSprite();
	player.GetSpriteComponent()->SetSprite("Images\\player.png");
	player.AddCollision2DComponent();
	player.AddBehaviour();
	player.SetBehaviour(new RocketBehaviour);

	Entity floor("Floor");
	floor.AddTransform();
	floor.AddSprite();
	floor.GetSpriteComponent()->SetSprite("Images\\floor.png");

	Entity wall("Wall");
	wall.AddTransform();
	wall.AddSprite();
	wall.GetSpriteComponent()->SetSprite("Images\\wall.png");
	wall.AddCollision2DComponent();

	std::vector<Entity> instances; //creating a vector of instances that will hold the actual entity objects

	//create a camera for the game
	Camera camera(windowWidth, windowHeight);
	camera.SetEntityToFollow(&player, windowWidth/2, windowHeight/2);

	//instantiate them here

	//first the level
	/*for (int xx = 0; xx < 20; xx++)
	{
		for (int yy = 0; yy < 20; yy++)
		{
			Entity newInstance = floor;
			instances.push_back(newInstance);
			game.GetSceneGraph(0)->Instantiate(&instances[instances.size() - 1], glm::vec2(xx * 32, yy * 32), 0);
		}
	}*/
	
	game.GetSceneGraph(0)->Instantiate(&player, glm::vec2(320, 320), 0);

	//instantiate the camera here
	game.GetSceneGraph(0)->Instantiate(&camera, glm::vec2(0, 0));

	game.Run(0);

	return 0; //Return success
}

//to do:
//behaviour system (update(deltatime))
//input system (implement new OnKeyPressed etc..)