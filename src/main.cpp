#include <cstdio>
#include "SdlContextWrapper.h"
#include "BlackWindowCase.h"
#include "SimpleTriangleCase.h"
#include "ColoredTriangleCase.h"

int main(int argc __attribute__((unused)), char* args[] __attribute__((unused)))
{

	/* Cases */
	//auto testCase = BlackWindowCase();
	//auto testCase = SimpleTriangleCase();
	auto testCase = ColoredTriangleCase();

	SdlContextWrapper wrapper(&testCase);
	if(!wrapper.Init())
	{
		wrapper.Close();
		return -1;
	}

	wrapper.Start();

	wrapper.Close();
	return 0;
}
