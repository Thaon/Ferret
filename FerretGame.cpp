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
	float seconds = float(currentTime - m_lastTime);
	m_lastTime = currentTime;
	return seconds;
}

void FerretGame::Init(int windowWidth, int windowHeight, int BPP)
{
	//this is our windowing system
	window = cWNDManager::getInstance();

	//This is our render system
	RenderSystem renderSys;

	//The example OpenGL code
	windowOGL theOGLWnd;

	// Attach the keyboard manager
	theInputMgr = new cInputMgr;
	window->attachInputMgr(theInputMgr);

	// Cube

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

	//RenderSystem renderSys;
	sceneGraph = new Scenegraph;
	//InputSystem input; actually not needed...

	// This is the input manager
	cInputMgr* theInputMgr = cInputMgr::getInstance();
	//Clear key buffers
	theInputMgr->clearBuffers(theInputMgr->KEYS_DOWN_BUFFER | theInputMgr->KEYS_PRESSED_BUFFER);
}

bool FerretGame::isRunning()
{
	return m_isRunning;
}

int FerretGame::Run()
{
	m_isRunning = true;

	//we are starting the game, therefore we call start on every Entity in the Scenegraph
	for each (Entity* gameObject in sceneGraph->GetEntities())
	{
		if (gameObject->GetBehaviour() != NULL)
		{
			gameObject->GetBehaviour()->SetInput(theInputMgr);//put this in the input system instead!
			gameObject->GetBehaviour()->SetTransform(gameObject->GetTransform());
			gameObject->GetBehaviour()->SetSpriteComponent(gameObject->GetSpriteComponent());
			gameObject->GetBehaviour()->Start();
		}
	}
	while (isRunning())
	{
		window->processWNDEvents(); //Process any window events

		//Update entities
		for each (Entity* gameObject in sceneGraph->GetEntities())
		{
			if (gameObject->GetBehaviour() != NULL)
			{
				gameObject->GetBehaviour()->Update();
			}
		}

		//Calculate collisions here

		//We get the time that passed since the last frame
		float elapsedTime = GetElapsedSeconds();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Render all the sprites here!!
		renderSys.Render(sceneGraph);
		window->swapBuffers();
		if (!window->isWNDRunning())
		{
			m_isRunning = false;
		}
	}

	//theOGLWnd.shutdown(); //Free any resources Seems a bit unnecessary as the method is empty...
	window->destroyWND(); //Destroy the program window
	return 1;
}