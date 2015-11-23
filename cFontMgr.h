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

	std::map<LPCSTR, cFont*> gameFonts;

public:
	cFontMgr();								// Default Constructor
	~cFontMgr();							// Destructor.
	void addFont(LPCSTR fontName, LPCSTR fileName, int fontSize);  // add font to the Font collection
	cFont* getFont(LPCSTR fontName);				// return the font for use
	void deleteFont();								// delete font.

};