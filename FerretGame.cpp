#include "FerretGame.h"

static FerretGame* pInstance = NULL;

FerretGame::FerretGame()
{
}


FerretGame::~FerretGame()
{
}

float FerretGame::GetElapsedSeconds()
{
	float currentTime = float(GetTickCount()) / 1000.0f;
	return currentTime;
}

void FerretGame::Init(int windowWidth, int windowHeight, int BPP)
{
	//this is our windowing system
	window = cWNDManager::getInstance();

	//The example OpenGL code
	windowOGL theOGLWnd;

	// Attach the keyboard manager
	theInputMgr = new cInputMgr;
	window->attachInputMgr(theInputMgr);

	//Clear key buffers
	theInputMgr->clearBuffers(theInputMgr->KEYS_DOWN_BUFFER | theInputMgr->KEYS_PRESSED_BUFFER);

	//create the font manager
	fontMgr = new cFontMgr;

	//Attempt to create the window
	if (!window->createWND(windowWidth, windowHeight, BPP))
	{
		//If it fails

		MessageBox(NULL, "Unable to create the OpenGL Window", "An error occurred", MB_ICONERROR | MB_OK);
		window->destroyWND(); //Reset the display and exit
		return;
	}

	if (!theOGLWnd.initOGL(windowWidth, windowHeight)) //Initialize our example
	{
		MessageBox(NULL, "Could not initialize the application", "An error occurred", MB_ICONERROR | MB_OK);
		window->destroyWND(); //Reset the display and exit
		return;
	}

	//sceneGraph = new Scenegraph; not creating the scenegraph from here anymore!

	//This is our render system
	renderSys = new RenderSystem;

	//create the audio manager
	audioMgr = new cSoundMgr();

	//and this is our Behaviour system
	behaviourSys = new BehaviourSystem;

	//this is the collision system... quite obviously
	collisionSys = new CollisionSystem;
}

bool FerretGame::isRunning()
{
	return m_isRunning;
}

void FerretGame::ChangeScene(int activeScene)
{
	behaviourSys->Start(sceneGraph[activeScene], theInputMgr, fontMgr, audioMgr);
}

int FerretGame::Run(int activeScene)
{
	m_isRunning = true;

	//we are starting the game, therefore we call start on every Entity in the Scenegraph
	behaviourSys->Start(sceneGraph[activeScene], theInputMgr, fontMgr, audioMgr);

	float oldTime = GetElapsedSeconds();

	while (isRunning())
	{
		theInputMgr->setLeftMouseBtn(false); //resetting the mouse state

		float newTime = GetElapsedSeconds();
		deltaTime = newTime - oldTime;

		window->processWNDEvents(); //Process any window events

		//update all the cameras
		for each (Camera* camera in sceneGraph[activeScene]->GetCameras())
		{
			camera->Update(deltaTime);
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Render all the sprites here!!
		renderSys->Render(sceneGraph[activeScene]);

		//translating the scene according to the camera coordinates so that when text is drawn either during collisions or from behaviors, it will be in the correct position
		if (sceneGraph[activeScene]->GetCameras().size() > 0 && sceneGraph[activeScene]->GetCameras()[0] != NULL)
			glTranslatef(-(sceneGraph[activeScene]->GetCameras()[0]->GetPosition().x), -(sceneGraph[activeScene]->GetCameras()[0]->GetPosition().y), 0.0f);
		
		//Calculate collisions here
		collisionSys->Update(sceneGraph[activeScene]);
		//Update entities
		behaviourSys->Update(deltaTime);
		if (sceneGraph[activeScene]->GetCameras().size() > 0 && sceneGraph[activeScene]->GetCameras()[0] != NULL)
			glTranslatef((sceneGraph[activeScene]->GetCameras()[0]->GetPosition().x), (sceneGraph[activeScene]->GetCameras()[0]->GetPosition().y), 0.0f);

		if (!window->isWNDRunning())
		{
			m_isRunning = false;
		}

		window->swapBuffers();

		//We update the delta time
		oldTime = newTime;



		//here we get into the Pong game specs: I could not find a way to work around this as the changing scene method must be called from within the FerretGame class, a bit hacky, but gets the job done.
		//on second thought I could have used signals and slots... next time, next time...
		if (activeScene == 0) //we are in the menu
		{
			if (sceneGraph[activeScene]->Find("Main Menu")->GetBehaviour()->GetGameState() == 1) //we are switching to the game scene
			{
				activeScene = 1;
				ChangeScene(activeScene); //going to the game scene!
			}
			
			if (sceneGraph[activeScene]->Find("Main Menu")->GetBehaviour()->GetGameState() == 2) //we are going back to DOS
			{
				m_isRunning = false;
				return 0;
			}
		}
		if (activeScene == 1) //if we are in the game
		{
			if (sceneGraph[activeScene]->Find("Ball")->GetBehaviour()->GetGameState() == 2) //goal was scored by AI
			{
				//reset game state and game until the score is more than 5
				sceneGraph[activeScene]->Find("Ball")->GetBehaviour()->SetGameState(-1);
				sceneGraph[activeScene]->Find("Points counter")->GetBehaviour()->Signal("Increase Ai Points");
				activeScene = 1;
				ChangeScene(activeScene); //reloads the current scene
			}

			if (sceneGraph[activeScene]->Find("Ball")->GetBehaviour()->GetGameState() == 1) //goal was scored by player
			{
				//reset game state and game until the score is more than 5
				sceneGraph[activeScene]->Find("Ball")->GetBehaviour()->SetGameState(-1);
				sceneGraph[activeScene]->Find("Points counter")->GetBehaviour()->Signal("Increase Player Points");
				activeScene = 1;
				ChangeScene(activeScene);
			}

			if (sceneGraph[activeScene]->Find("Points counter")->GetBehaviour()->GetGameState() == 2) //player won
			{
				sceneGraph[activeScene]->Find("Points counter")->GetBehaviour()->Signal("Reset Points");
				activeScene = 2;
				ChangeScene(activeScene); //going to the won game scene
			}

			if (sceneGraph[activeScene]->Find("Points counter")->GetBehaviour()->GetGameState() == 1) //player won
			{
				sceneGraph[activeScene]->Find("Points counter")->GetBehaviour()->Signal("Reset Points");
				activeScene = 3;
				ChangeScene(activeScene); //going to the lost game scene
			}
		}
		if (activeScene == 2) //if we are in the win scene
		{
			if (sceneGraph[activeScene]->Find("Win Screen Menu")->GetBehaviour()->GetGameState() == 1) //we are playing again
			{
				activeScene = 1;
				ChangeScene(activeScene); //going to the game scene!
			}

			if (sceneGraph[activeScene]->Find("Win Screen Menu")->GetBehaviour()->GetGameState() == 2) //we are going back to DOS
			{
				m_isRunning = false;
				return 0;
			}
		}

		if (activeScene == 3) //if we are in the lose scene
		{
			if (sceneGraph[activeScene]->Find("Lose Screen Menu")->GetBehaviour()->GetGameState() == 1) //we are playing again
			{
				activeScene = 1;
				ChangeScene(activeScene); //going to the game scene!
			}

			if (sceneGraph[activeScene]->Find("Lose Screen Menu")->GetBehaviour()->GetGameState() == 2) //we are going back to DOS
			{
				m_isRunning = false;
				return 0;
			}
		}
	}

	//theOGLWnd.shutdown(); //Free any resources Seems a bit unnecessary as the method is empty...
	window->destroyWND(); //Destroy the program window
	return 1;
}