#include <cstdio>
#include <SDL2/SDL.h>
#include <gl/glew.h>
#include <gl/glu.h>

const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH = 800;

bool Init();
bool InitGL();
void GameLoop();
void Render();
void Close();
void printProgramLog( GLuint program );
void printShaderLog( GLuint shader );

SDL_Window* _window = nullptr;
SDL_GLContext _context;

//Graphics program
GLuint gProgramID = 0;
GLint gVertexPos2DLocation = -1;
GLuint gVBO = 0;
GLuint gIBO = 0;

int main(int argc __attribute__((unused)), char* args[] __attribute__((unused)))
{
	if(!Init())
	{
		Close();
		return -1;
	}

	GameLoop();

	Close();
	return 0;
}

bool Init()
{
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError()); 
		return false;
	}

	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1);

	_window = SDL_CreateWindow( "SDL Tutorial",
								SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED,
								WINDOW_WIDTH,
								WINDOW_HEIGHT,
								SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
	if( _window == nullptr )
	{ 
	 	printf( "Window could not be created! SDL_Error: %s\n",
	 			 SDL_GetError() ); 
	 	return false;
	}

	_context = SDL_GL_CreateContext(_window);

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

	//use Vsync
	if(SDL_GL_SetSwapInterval(1) < 0)
	{
		printf( "Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError() );
		return false;
	}

	if(!InitGL())
	{
		printf("Unable to initialize OpenGL\n");
		return false;
	}

	return true;
}

bool InitGL()
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

	return true;
}

void GameLoop()
{
	auto quit = false;
	SDL_Event e;

	while(!quit)
	{
		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		Render();
		SDL_GL_SwapWindow(_window);
	}
}

void Render()
{	
	glClear( GL_COLOR_BUFFER_BIT );
}

void Close()
{
	SDL_DestroyWindow(_window);
	SDL_Quit();
}
