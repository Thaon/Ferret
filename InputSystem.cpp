#include "InputSystem.h"


InputSystem::InputSystem()
{
}


InputSystem::~InputSystem()
{
}

void InputSystem::Init()
{
	// This is the input manager
	theInputMgr = cInputMgr::getInstance();
	//Clear key buffers
	theInputMgr->clearBuffers(theInputMgr->KEYS_DOWN_BUFFER | theInputMgr->KEYS_PRESSED_BUFFER);
}
