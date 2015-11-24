/*
==========================================================================
cFont.cpp
==========================================================================
*/
#pragma warning ( disable : 4996 )
#include "cFont.h"
using namespace std;

/*
==========================================================================
Default Constructor
==========================================================================
*/
cFont::cFont()
{
	theFont = NULL;
}
/*
==========================================================================
Overloaded constructor
==========================================================================
*/
cFont::cFont(LPCSTR fontFileName, const unsigned int fontSize)
{
	theFont = new FTGLTextureFont(fontFileName);

	//FT_Error error = theFont->Error();
	//MessageBox(NULL, (LPCSTR)error, "Error Code", MB_OK);

	if (theFont->Error())
	{
		MessageBox(NULL, "Unable to create the required Font!", "Error!", MB_ICONERROR | MB_OK);
		delete theFont;
		return;
	}

	if (!theFont->FaceSize(fontSize))
	{
		MessageBox(NULL, "Unable to set desired size for Font!", "An error occurred", MB_ICONERROR | MB_OK);
		delete theFont;
	}
}

/*
==========================================================================
Destructor
==========================================================================
*/
cFont::~cFont()
{
	delete theFont;
}
/*
==========================================================================
get the pointer to the font
==========================================================================
*/
FTFont* cFont::getFont()
{
	return theFont;
}

/*
==========================================================================
Render the text using the desired font
==========================================================================
*/
void cFont::printText(LPCSTR text, FTPoint textPos)
{
	glPushMatrix();

	theFont->Render(text, -1, textPos);

	glPopMatrix();
}
