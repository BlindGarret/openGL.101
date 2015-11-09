#include <cstdio>
#include "SdlContextWrapper.h"
#include "BlackWindowCase.h"

int main(int argc __attribute__((unused)), char* args[] __attribute__((unused)))
{

	/* Cases */
	auto testCase = BlackWindowCase();

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
