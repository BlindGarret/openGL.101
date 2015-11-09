#include <cstdio>
#include <SDL2/SDL.h>

const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH = 800;

int main()
{
	SDL_Window* window = nullptr;
	SDL_Surface* surface = nullptr;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError()); 
		return -1;
	}

	window = SDL_CreateWindow( "SDL Tutorial",
								SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED,
								WINDOW_WIDTH,
								WINDOW_HEIGHT,
								SDL_WINDOW_SHOWN );
	if( window == NULL )
	{ 
	 	printf( "Window could not be created! SDL_Error: %s\n",
	 			 SDL_GetError() ); 
	 	return -1;
	}

	surface = SDL_GetWindowSurface(window);
									SDL_FillRect(surface,
									NULL,
									SDL_MapRGB( surface->format,
												0xFF,
												0xFF,
												0xFF ));
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}