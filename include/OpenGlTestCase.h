#ifndef OPENGLTESTCASE_HEADER
#define OPENGLTESTCASE_HEADER

#include <SDL2/SDL.h>

class OpenGlTestCase
{
public:
	virtual void Render() = 0;
	virtual bool Init() = 0;
	virtual void Close() = 0;
	virtual void HandleInput(SDL_Event e) = 0;
	virtual int OpenGlMajorVersion() = 0;	
	virtual int OpenGlMinorVersion() = 0;
	virtual int WindowHeight() = 0;
	virtual int WindowWidth() = 0;
	virtual bool IsQuit() = 0;
};

#endif
