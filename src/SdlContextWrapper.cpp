#include "SdlContextWrapper.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/glu.h>
#include <cstdio>

SdlContextWrapper::SdlContextWrapper(OpenGlTestCase* testCase)
	{
		_testCase = testCase;
	}

	bool SdlContextWrapper::Init()
	{

		if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError()); 
			return false;
		}

		SDL_GL_SetAttribute( SDL_GL_ACCELERATED_VISUAL, 1);
		SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 1);

		_window = SDL_CreateWindow( "SDL Tutorial",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									_testCase->WindowWidth(),
									_testCase->WindowHeight(),
									SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
		if( _window == nullptr )
		{ 
		 	printf( "Window could not be createdated! SDL_Error: %s\n",
		 			 SDL_GetError() ); 
		 	return false;
		}

		_context = SDL_GL_CreateContext(_window);
		SDL_GL_MakeCurrent(_window, _context);

		if(_context == NULL)
		{
			printf( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
			return false;
		}

		glewExperimental = GL_TRUE;
		GLenum glewError = glewInit();

		if(glewError != GLEW_OK)
		{
			printf( "Error initializing GLEW! %s\n", glewGetErrorString( glewError ) );
			return false;
		}

   		printf("GL version: %s\n", glGetString(GL_VERSION));

		//use Vsync
		if(SDL_GL_SetSwapInterval(1) < 0)
		{
			printf( "Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError() );
			return false;
		}

		if(!_testCase->Init())
		{
			printf("Unable to initialize TestCase\n");
			return false;
		}

		return true;
	}

	void SdlContextWrapper::Start()
	{
		auto quit = false;
		SDL_Event e;

		while(!quit)
		{
			while(SDL_PollEvent(&e) != 0)
			{
				if(e.type == SDL_QUIT || _testCase->IsQuit())
				{
					quit = true;
				}
				_testCase->HandleInput(e);
			}

			_testCase->Render();
			SDL_GL_SwapWindow(_window);
		}
	}

	void SdlContextWrapper::Close()
	{
		SDL_DestroyWindow(_window);
		SDL_Quit();
	}
