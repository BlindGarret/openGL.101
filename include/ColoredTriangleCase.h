#ifndef COLOREDTRIANGLECASE_HEADER
#define COLOREDTRIANGLECASE_HEADER
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/glu.h>
#include "OpenGlTestCase.h"

class ColoredTriangleCase : public OpenGlTestCase
{
public:
	virtual void Render();
	virtual bool Init();
	virtual void Close();
	virtual void HandleInput(SDL_Event e);
	virtual int WindowHeight();
	virtual int WindowWidth();
	virtual bool IsQuit();

private:
	GLuint _programId;
	GLint _attributeCoord2d;
	GLint _attributeVertexColor;
	GLuint _vboTriangle;
	GLuint _vboTriangleColors;
};

#endif
