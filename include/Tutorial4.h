#ifndef TUTORIAL4_HEADER
#define TUTORIAL4_HEADER
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/glu.h>
#include "OpenGlTestCase.h"

class Tutorial4 : public OpenGlTestCase
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

private:
	GLuint _programId;
	GLuint _vboTriangle;
};

#endif
