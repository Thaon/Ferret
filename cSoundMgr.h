/*
==========================================================================
cSoundMgr.h
==========================================================================
*/

#pragma once

#include "cSound.h"
#include <map>

using namespace std;

class cSoundMgr
{
private:
	ALCcontext *m_OALContext;
	ALCdevice *m_OALDevice;

public:
	cSoundMgr();
	~cSoundMgr();
	map <LPCSTR, cSound*> gameSnds;
	void createContext();

public:
	void add(LPCSTR sndName, LPCSTR fileName);
	cSound* getSnd(LPCSTR sndName);
	void deleteSnd();
};