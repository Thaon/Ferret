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

	sceneGraph = new Scenegraph;

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

int FerretGame::Run()
{
	m_isRunning = true;

	//we are starting the game, therefore we call start on every Entity in the Scenegraph
	behaviourSys->Start(sceneGraph, theInputMgr, fontMgr, audioMgr);

	float oldTime = GetElapsedSeconds();

	while (isRunning())
	{
		float newTime = GetElapsedSeconds();
		deltaTime = newTime - oldTime;

		window->processWNDEvents(); //Process any window events



		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Render all the sprites here!!
		renderSys->Render(sceneGraph);
		//Update entities
		behaviourSys->Update(deltaTime);
		//Calculate collisions here
		collisionSys->Update(sceneGraph);
		if (!window->isWNDRunning())
		{
			m_isRunning = false;
		}
		window->swapBuffers();

		//We update the delta time
		oldTime = newTime;
	}

	//theOGLWnd.shutdown(); //Free any resources Seems a bit unnecessary as the method is empty...
	window->destroyWND(); //Destroy the program window
	return 1;
}