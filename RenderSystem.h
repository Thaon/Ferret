#pragma once

#include "RenderSystem.h"
#include <windows.h>
#include "windowOGL.h"
#include <ctime>
#include <iostream>
#include "GL/gl.h"
#include "wglext.h"
#include "Scenegraph.h"
#include "InputSystem.h"


class RenderSystem
{
public:
	int Init(int width, int height, int BPP);
	void RenderSprite(Entity* entity);
	void Render(Scenegraph* sceneGraph);

	bool createWND(int width, int height, int bpp);
	void destroyWND();
	void processWNDEvents();
	void attachOGLWnd(windowOGL* winOGL);

	bool isWNDRunning(); //Is the window running?

	HWND getWNDHandle(); // Return window handle.
	HDC getWNDDC(); // Return Device context

	void swapBuffers() { SwapBuffers(m_hdc); }

	static RenderSystem* getInstance();

	RenderSystem();
	~RenderSystem();

private:
	static RenderSystem* pInstance;
	static InputSystem* m_inputSystem;

	//don't need a reference to the scenegraph as it will be passed to the render method by the FerretGame class

	std::string m_gameTitle;

	windowOGL* m_winOGL; //A link to the OGL window

	bool m_isRunning; //Is the window still running?

	HGLRC m_hglrc; //Rendering context
	RECT m_windowRect; //Window bounds
	HINSTANCE m_hinstance; //Application instance
	WNDCLASSEX m_windowClass;

	void setupPixelFormat(void);
	windowOGL* getAttachedWND();

	float m_lastTime;

	HWND m_hwnd; //Window handle
	HDC m_hdc; //Device context
};

