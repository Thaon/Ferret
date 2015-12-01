#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#define GLX_GLXEXT_LEGACY //Must be declared so that our local glxext.h is picked up, rather than the system one

#include "FerretGame.h"

#include "PlayerBehaviour.h"
#include "Ball.h"

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR cmdLine,
	int cmdShow)
{

	//Set our window settings
	const int windowWidth = 1280;
	const int windowHeight = 768;
	const int windowBPP = 16;

	FerretGame game;
	game.Init(windowWidth, windowHeight, windowBPP);
	game.CreateSceneGraph();// we create our scenegraph 0 and 1 here
	game.CreateSceneGraph();

	//declare our entities here
	Entity player("Player Paddle");
	player.AddTransform();
	player.AddSprite();
	player.GetSpriteComponent()->SetSprite("Images\\player.png");
	player.AddCollision2DComponent();
	player.AddBehaviour();
	player.SetBehaviour(new PlayerBehaviour);

	Entity ball("Ball");
	ball.AddTransform();
	ball.AddSprite();
	ball.GetSpriteComponent()->SetSprite("Images\\ball.png");
	ball.AddCollision2DComponent();
	ball.AddBehaviour();
	ball.SetBehaviour(new Ball);

	Entity ai("AI Paddle");
	ai.AddTransform();
	ai.AddSprite();
	ai.GetSpriteComponent()->SetSprite("Images\\wall.png");
	ai.AddCollision2DComponent();
	ai.AddBehaviour();
	//ai.SetBehaviour(new RocketBehaviour);

	//create a camera for the game
	Camera camera(windowWidth, windowHeight);
	//camera.SetEntityToFollow(&player, windowWidth/2, windowHeight/2);


	//instantiate them here

	
	game.GetSceneGraph(1)->Instantiate(&player, glm::vec2(0, 320), 0);
	game.GetSceneGraph(1)->Instantiate(&ball, glm::vec2(640, 320), 0);

	//instantiate the cameras here
	game.GetSceneGraph(1)->Instantiate(&camera, glm::vec2(0, 0));


	game.Run(1);

	return 0; //Return success
}

//to do:
//behaviour system (update(deltatime))
//input system (implement new OnKeyPressed etc..)