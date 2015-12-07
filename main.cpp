#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#define GLX_GLXEXT_LEGACY //Must be declared so that our local glxext.h is picked up, rather than the system one

#include "FerretGame.h"

#include "PlayerBehaviour.h"
#include "Ball.h"
#include "AIBehaviour.h"
#include "PointsCounterBehaviour.h"
#include "MenuBehaviour.h"
#include "WinScreenBehaviour.h"
#include "LoseScreenBehaviour.h"

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

	//declare our entities here

	//MENU
	Entity menuBkg("Menu Background");
	menuBkg.AddTransform();
	menuBkg.AddSprite();
	menuBkg.GetSpriteComponent()->SetSprite("Images\\Menu.png");

	Entity menu("Main Menu");
	menu.AddTransform();
	menu.AddBehaviour();
	menu.SetBehaviour(new MenuBehaviour);


	//GAME

	Entity background("Background");
	background.AddTransform();
	background.AddSprite();
	background.GetSpriteComponent()->SetSprite("Images\\BKGND.png");

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
	ai.GetSpriteComponent()->SetSprite("Images\\ai.png");
	ai.AddCollision2DComponent();
	ai.AddBehaviour();
	AIBehaviour aiBehaviour;
	ai.SetBehaviour(&aiBehaviour);
	aiBehaviour.m_ball = &ball; //if I store a reference to the behaviour I can then access it's methods and member variables!

	Entity pointsCounter("Points counter");
	pointsCounter.AddBehaviour();
	PointsCounterBehaviour pointsCounterBehaviour;
	pointsCounter.SetBehaviour(&pointsCounterBehaviour);
	pointsCounterBehaviour.ResetPoints();

	//Win and Lose screens

	Entity winScreen("Win Screen Menu");
	winScreen.AddSprite();
	winScreen.GetSpriteComponent()->SetSprite("Images\\WinScreen.png");
	winScreen.AddBehaviour();
	winScreen.SetBehaviour(new WinScreenBehaviour);


	Entity loseScreen("Lose Screen Menu");
	loseScreen.AddSprite();
	loseScreen.GetSpriteComponent()->SetSprite("Images\\LoseScreen.png");
	loseScreen.AddBehaviour();
	loseScreen.SetBehaviour(new LoseScreenBehaviour);

	//create a camera for the game
	Camera camera(windowWidth, windowHeight);
	//camera.SetEntityToFollow(&player, windowWidth/2, windowHeight/2);


	//instantiate them here

	//Menu scene
	game.CreateSceneGraph();// we create our scenegraphs for the game here
	game.GetSceneGraph(0)->Instantiate(&menuBkg, glm::vec2(0, 0), 0);
	game.GetSceneGraph(0)->Instantiate(&menu, glm::vec2(0, 0), 0);

	//Game scene
	game.CreateSceneGraph();
	game.GetSceneGraph(1)->Instantiate(&background, glm::vec2(0, 0), 0);
	game.GetSceneGraph(1)->Instantiate(&player, glm::vec2(10, 320), 0);
	game.GetSceneGraph(1)->Instantiate(&ai, glm::vec2(1190, 320), 0);
	game.GetSceneGraph(1)->Instantiate(&ball, glm::vec2(640, 320), 0);
	game.GetSceneGraph(1)->Instantiate(&pointsCounter, glm::vec2(0, 0), 0);

	//Win scene
	game.CreateSceneGraph();
	game.GetSceneGraph(2)->Instantiate(&winScreen, glm::vec2(0, 0), 0);

	//Lose scene
	game.CreateSceneGraph();
	game.GetSceneGraph(3)->Instantiate(&loseScreen, glm::vec2(0, 0), 0);

	//instantiate the cameras here
	game.GetSceneGraph(0)->Instantiate(&camera, glm::vec2(0, 0));
	game.GetSceneGraph(1)->Instantiate(&camera, glm::vec2(0, 0));
	game.GetSceneGraph(2)->Instantiate(&camera, glm::vec2(0, 0));
	game.GetSceneGraph(3)->Instantiate(&camera, glm::vec2(0, 0));

	game.Run(0);

	return 0; //Return success
}

//to do:
//behaviour system (update(deltatime))
//input system (implement new OnKeyPressed etc..)