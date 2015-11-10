#ifndef SIMPLETRIANGLECASE_HEADER
#define SIMPLETRIANGLECASE_HEADER
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/glu.h>
#include "OpenGlTestCase.h"

class SimpleTriangleCase : public OpenGlTestCase
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
	//methods
	bool TryCompileShader(const char* shader, GLenum shaderType, GLuint& outshaderId);
	bool TryLinkGlslProgram(GLuint vertexShaderId, GLuint fragmentShaderId, GLuint& outProgramId);

	GLuint _programId;
	GLint _attributeCoord2d;
};

#endif
