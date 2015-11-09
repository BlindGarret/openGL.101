#ifndef SDLCONTEXTWRAPPER_HEADER
#define SDLCONTEXTWRAPPER_HEADER

#include "OpenGlTestCase.h"

class SdlContextWrapper
{
public:
	SdlContextWrapper(OpenGlTestCase* testCase);
	bool Init();
	void Start();
	void Close();
private:
	OpenGlTestCase* _testCase;
	SDL_Window* _window = nullptr;
	SDL_GLContext _context;
};

#endif
