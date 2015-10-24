#include "InputSystem.h"


InputSystem::InputSystem()
{
}


InputSystem::~InputSystem()
{
}


LRESULT CALLBACK InputSystem::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	RenderSystem* theWindow = NULL;
	switch (uMsg)
	{
	case WM_CREATE:         // window creation
	{
		pInstance->m_hdc = GetDC(hWnd);
		pInstance->setupPixelFormat();

		//Set the version that we want, in this case 3.0
		int attribs[] = {
			WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
			WGL_CONTEXT_MINOR_VERSION_ARB, 0,
			0 }; //zero indicates the end of the array

				 //Create temporary context so we can get a pointer to the function
		HGLRC tmpContext = wglCreateContext(pInstance->m_hdc);
		//Make it current
		wglMakeCurrent(pInstance->m_hdc, tmpContext);

		//Get the function pointer
		wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");

		//If this is NULL then OpenGL 3.0 is not supported
		if (!wglCreateContextAttribsARB)
		{
			std::cerr << "OpenGL 3.0 is not supported, falling back to GL 2.1" << std::endl;
			pInstance->m_hglrc = tmpContext;
		}
		else
		{
			// Create an OpenGL 3.0 context using the new function
			pInstance->m_hglrc = wglCreateContextAttribsARB(pInstance->m_hdc, 0, attribs);
			//Delete the temporary context
			wglDeleteContext(tmpContext);
		}

		//Make the GL3 context current
		wglMakeCurrent(pInstance->m_hdc, pInstance->m_hglrc);

		pInstance->m_isRunning = true; //Mark our window as running
	}
	break;
	case WM_DESTROY: // window destroy
	case WM_CLOSE: // windows is closing
		wglMakeCurrent(pInstance->m_hdc, NULL);
		wglDeleteContext(pInstance->m_hglrc);
		pInstance->m_isRunning = false; //Stop the main loop
		PostQuitMessage(0); //Send a WM_QUIT message
		return 0;
		break;
	case WM_SIZE:
	{
		int height = HIWORD(lParam);        // retrieve width and height
		int width = LOWORD(lParam);
		pInstance->getAttachedWND()->onResize(width, height); //Call the example's resize method
	}
	break;
	case WM_KEYDOWN:
	{
		if (wParam == VK_ESCAPE) //If the escape key was pressed
		{
			DestroyWindow(pInstance->m_hwnd); //Send a WM_DESTROY message
		}
		pInstance->m_InputMgr->keyDown(wParam);
		return 0;
	}
	case WM_KEYUP:
	{

		pInstance->m_InputMgr->keyUp(wParam);
		return 0;
	}

	break;
	default:
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}