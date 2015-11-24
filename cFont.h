/*
==========================================================================
cFont.h
==========================================================================
*/

#pragma once

#include <Windows.h>
#include <map>
#include <FTGL\ftgl.h>
#include <GL/glut.h>

class cFont
{
private:
	FTFont* theFont;

public:
	cFont();
	cFont(LPCSTR fontFileName, const unsigned int fontSize);
	~cFont();
	FTFont* getFont();
	void printText(LPCSTR text, FTPoint textPos);
};
