#include "RenderSystem.h"

RenderSystem* RenderSystem::pInstance = NULL;

typedef HGLRC(APIENTRYP PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC, HGLRC, const int*);
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;

RenderSystem::RenderSystem()
{
	m_winOGL = NULL;
	m_hinstance = NULL;
	m_lastTime = 0;
}


RenderSystem::~RenderSystem()
{
}


int RenderSystem::Init(int width, int height, int BPP)
{
	//This is our window
	static RenderSystem* pgmWNDMgr = RenderSystem::getInstance();

	//The example OpenGL code
	windowOGL theOGLWnd;

	//Attach our the OpenGL window
	pgmWNDMgr->attachOGLWnd(&theOGLWnd);

	// Attach the keyboard manager
	//pgmWNDMgr->attachInputMgr(theInputMgr);

	// Cube

	//Attempt to create the window
	if (!pgmWNDMgr->createWND(width, height, BPP))
	{
		//If it fails

		MessageBox(NULL, "Unable to create the OpenGL Window", "An error occurred", MB_ICONERROR | MB_OK);
		pgmWNDMgr->destroyWND(); //Reset the display and exit
		return 1;
	}

	if (!theOGLWnd.initOGL(width, height)) //Initialize our example
	{
		MessageBox(NULL, "Could not initialize the application", "An error occurred", MB_ICONERROR | MB_OK);
		pgmWNDMgr->destroyWND(); //Reset the display and exit
		return 1;
	}


}

RenderSystem* RenderSystem::getInstance() // singleton
{
	if (pInstance == NULL)
	{
		pInstance = new RenderSystem();
	}
	return RenderSystem::pInstance;
}

bool RenderSystem::createWND(int width, int height, int bpp)
{
	DWORD      dwExStyle;       // Window Extended Style
	DWORD      dwStyle;         // Window Style

	m_windowRect.left = (long)0; // Set Left Value To 0
	m_windowRect.right = (long)width; // Set Right Value To Requested Width
	m_windowRect.top = (long)0;  // Set Top Value To 0
	m_windowRect.bottom = (long)height;   // Set Bottom Value To Requested Height

										  // fill out the window class structure
	m_windowClass.cbSize = sizeof(WNDCLASSEX);
	m_windowClass.style = CS_HREDRAW | CS_VREDRAW;
	m_windowClass.lpfnWndProc = (WNDPROC)m_inputSystem->WndProc; //We set our static method as the event handler (WNDPROC) in the input system!
	m_windowClass.cbClsExtra = 0;
	m_windowClass.cbWndExtra = 0;
	m_windowClass.hInstance = m_hinstance;
	m_windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);  // default icon
	m_windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);      // default arrow
	m_windowClass.hbrBackground = NULL;                             // don't need background
	m_windowClass.lpszMenuName = NULL;                             // no menu
	m_windowClass.lpszClassName = "winOGL";
	m_windowClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);      // windows logo small icon

															  // register the windows class
	if (!RegisterClassEx(&m_windowClass))
	{
		return false;
	}

	dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;   // Window Extended Style
	dwStyle = WS_OVERLAPPEDWINDOW;                    // Windows Style

	AdjustWindowRectEx(&m_windowRect, dwStyle, false, dwExStyle);     // Adjust Window To True Requested Size

																	  // class registered, so now create our window
	m_hwnd = CreateWindowEx(NULL,                                 // extended style
		"winOGL",                          // class name
		m_gameTitle.c_str(),      // app name
		WS_OVERLAPPEDWINDOW,	// the window style
		CW_USEDEFAULT, // the starting x coordinate
		CW_USEDEFAULT, // the starting y coordinate
		m_windowRect.right - m_windowRect.left, // the pixel width of the window
		m_windowRect.bottom - m_windowRect.top, // the pixel height of the window
		NULL, // the parent window; NULL for desktop
		NULL, // the menu for the application; NULL for none
		m_hinstance, // the handle to the application instance
		this); // no values passed to the window

			   // check if window creation failed (hwnd would equal NULL)
	if (!m_hwnd)
		return 0;

	m_hdc = GetDC(m_hwnd);

	ShowWindow(m_hwnd, SW_SHOW);          // display the window
	UpdateWindow(m_hwnd);                 // update the window

	m_lastTime = GetTickCount() / 1000.0f; //Initialize the time
	return true;
}
void RenderSystem::destroyWND()
{
	ShowCursor(true);                       // Show Mouse Pointer
}

void RenderSystem::attachOGLWnd(windowOGL* OGLWindow)
{
	m_winOGL = OGLWindow;
}

bool RenderSystem::isWNDRunning()
{
	return m_isRunning;
}

HWND RenderSystem::getWNDHandle()               // Return window handle.
{
	return m_hwnd;
}

HDC RenderSystem::getWNDDC()
{
	return m_hdc;
}

void RenderSystem::processWNDEvents()
{
	MSG msg;

	//While there are messages in the queue, store them in msg
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		//Process the messages one-by-one
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void RenderSystem::setupPixelFormat(void)
{
	int pixelFormat;

	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),  // size
		1,                          // version
		PFD_SUPPORT_OPENGL |        // OpenGL window
		PFD_DRAW_TO_WINDOW |        // render to window
		PFD_DOUBLEBUFFER,           // support double-buffering
		PFD_TYPE_RGBA,              // color type
		32,                         // prefered color depth
		0, 0, 0, 0, 0, 0,           // color bits (ignored)
		0,                          // no alpha buffer
		0,                          // alpha bits (ignored)
		0,                          // no accumulation buffer
		0, 0, 0, 0,                 // accum bits (ignored)
		16,                         // depth buffer
		0,                          // no stencil buffer
		0,                          // no auxiliary buffers
		PFD_MAIN_PLANE,             // main layer
		0,                          // reserved
		0, 0, 0,                    // no layer, visible, damage masks
	};

	pixelFormat = ChoosePixelFormat(m_hdc, &pfd);
	SetPixelFormat(m_hdc, pixelFormat, &pfd);
}

windowOGL*  RenderSystem::getAttachedWND()
{
	return m_winOGL;
}

// WE NOW START WITH RENDERING INDIVIDUAL SPRITES!

void RenderSystem::RenderSprite(Entity* entity)
{
	glLoadIdentity();
	glPushMatrix();

	//glMatrixMode(GL_TEXTURE);
	glTranslatef(entity->GetSpriteComponent()->GetCenter().x, entity->GetSpriteComponent()->GetCenter().y, 0.0f);
	glRotatef(entity->GetTransform()->GetRotation(), 0.0f, 0.0f, 1.0f);
	glScalef(entity->GetTransform()->GetScale().x, entity->GetTransform()->GetScale().y, 1.0f);
	glTranslatef(-entity->GetSpriteComponent()->GetCenter().x, -entity->GetSpriteComponent()->GetCenter().y, 0.0f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, entity->GetSpriteComponent()->GetTexture()); // Binding of GLtexture name 
											   //glMatrixMode(GL_MODELVIEW);


	glBegin(GL_QUADS);
	glColor3f(255.0f, 255.0f, 255.0f);
	glTexCoord2f(entity->GetSpriteComponent()->GetTexCoordData()[0].x, entity->GetSpriteComponent()->GetTexCoordData()[0].y);
	glVertex2f(entity->GetTransform()->GetPosition().x, entity->GetTransform()->GetPosition().y);
	glTexCoord2f(entity->GetSpriteComponent()->GetTexCoordData()[1].x, entity->GetSpriteComponent()->GetTexCoordData()[1].y);
	glVertex2f(entity->GetTransform()->GetPosition().x + entity->GetSpriteComponent()->GetWidth(), entity->GetTransform()->GetPosition().y);
	glTexCoord2f(entity->GetSpriteComponent()->GetTexCoordData()[2].x, entity->GetSpriteComponent()->GetTexCoordData()[2].y);
	glVertex2f(entity->GetTransform()->GetPosition().x + entity->GetSpriteComponent()->GetWidth(), entity->GetTransform()->GetPosition().y + entity->GetSpriteComponent()->GetHeight());
	glTexCoord2f(entity->GetSpriteComponent()->GetTexCoordData()[3].x, entity->GetSpriteComponent()->GetTexCoordData()[3].y);
	glVertex2f(entity->GetTransform()->GetPosition().x, entity->GetTransform()->GetPosition().y + entity->GetSpriteComponent()->GetHeight());

	glEnd();

	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void RenderSystem::Render(Scenegraph* sceneGraph)
{
	for each (Entity entity in sceneGraph->GetEntities())
	{
		RenderSprite(&entity);
	}
}
