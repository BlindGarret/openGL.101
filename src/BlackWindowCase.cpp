#include "BlackWindowCase.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/glu.h>

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

