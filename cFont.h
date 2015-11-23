/*
==========================================================================
cFont.h
==========================================================================
*/

#pragma once

#include <Windows.h>
#include <map>
#include <FTGL\ftgl.h>

#include "RenderSystem.h"

class cFont
{
private:
	FTFont* theFont;

	RenderSystem* renderSystem;

public:
	cFont();
	cFont(LPCSTR fontFileName, int fontSize, RenderSystem* renderSys);
	~cFont();
	FTFont* getFont();
	void printText(LPCSTR text, FTPoint textPos);

};
