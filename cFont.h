/*
==========================================================================
cFont.h
==========================================================================
*/

#pragma once

#include <Windows.h>
#include <map>
#include <FTGL\ftgl.h>

class cFont
{
private:
	FTFont* theFont;

public:
	cFont();
	cFont(LPCSTR fontFileName, int fontSize);
	~cFont();
	FTFont* getFont();
	void printText(LPCSTR text, FTPoint textPos);

};
