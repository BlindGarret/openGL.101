#include "BlackWindowCase.h"
#include <SDL2/SDL.h>
#include <gl/glew.h>
#include <gl/glu.h>

void BlackWindowCase::Render()
{
	glClear( GL_COLOR_BUFFER_BIT );
}

bool BlackWindowCase::Init()
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

	return true;
}

void BlackWindowCase::Close()
{
	//do nothing
}

void BlackWindowCase::HandleInput(SDL_Event)
{
	//do nothing
}

int BlackWindowCase::OpenGlMajorVersion()
{
	return 3;
}
	
int BlackWindowCase::OpenGlMinorVersion()
{
	return 1;
}

int BlackWindowCase::WindowHeight()
{
	return 600;
}

int BlackWindowCase::WindowWidth()
{
	return 800;
}

bool BlackWindowCase::IsQuit()
{
	return false;
}

