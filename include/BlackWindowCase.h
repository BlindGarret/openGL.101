#ifndef BLACKWINDOWCASE_HEADER
#define BLACKWINDOWCASE_HEADER

#include "OpenGlTestCase.h"

class BlackWindowCase : public OpenGlTestCase
{
public:
	virtual void Render();
	virtual bool Init();
	virtual void Close();
	virtual void HandleInput(SDL_Event e);
	virtual int OpenGlMajorVersion();	
	virtual int OpenGlMinorVersion();
	virtual int WindowHeight();
	virtual int WindowWidth();
	virtual bool IsQuit();
};

#endif
