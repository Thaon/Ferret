/*
== == == == == == == == =
cFontMgr.h
- Header file for class definition - SPECIFICATION
- Header file for the InputMgr class
== == == == == == == == =
*/

#pragma once

#include "cFont.h"

class cFontMgr
{
private:

	map<LPCSTR, cFont*> gameFonts;
	RenderSystem* renderSys;

public:
	cFontMgr();								// Default Constructor
	cFontMgr(RenderSystem* renderSystem);
	~cFontMgr();							// Destructor.
	void addFont(LPCSTR fontName, LPCSTR fileName, int fontSize);  // add font to the Font collection
	cFont* getFont(LPCSTR fontName);				// return the font for use
	void deleteFont();								// delete font.

};