#include "Tutorial4.h"
#include "ShaderHelper.h"
#include "Vector3f.h"
#include <cstdio>
#include <string>

void Tutorial4::Render()
{
	glClear( GL_COLOR_BUFFER_BIT );

	glUseProgram(_programId);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _vboTriangle);
	glVertexAttribPointer(0,
						 3,
						 GL_FLOAT,
						 GL_FALSE,
						 0,
						 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}

bool Tutorial4::Init()
{
	if(!GLEW_VERSION_4_0)
	{
		printf("This computer cannot support required OpenGL version 2.0!\n");
		return false;
	}

	glClearColor( 0.0f, 0.0f, 1.0f, 1.0f );
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	auto shaderHelper = ShaderHelper();

	//vertex shader
	std::string vertexShader = "";
	if(!shaderHelper.TryReadShaderFile("shaders/SimpleNewVertex.vs", vertexShader))
	{
		printf("Could not open vertex file!\n");
		return false;
	}

	GLuint vertexShaderId;
	if(!shaderHelper.TryCompileVertexShader(vertexShader, vertexShaderId))
	{
		printf("Could not compile vertex shader!\n");
		return false;
	}

	//fragment shader
	std::string fragmentShader = "";
	if(!shaderHelper.TryReadShaderFile("shaders/SimpleNewFragment.fs", fragmentShader))
	{
		printf("Could not open fragment file!\n");
		return false;
	}

	GLuint fragmentShaderId;
	if(!shaderHelper.TryCompileFragmentShader(fragmentShader, fragmentShaderId))
	{
		printf("Could not compile fragment shader!\n");
		return false;
	}

	//link program
	if(!shaderHelper.TryLinkGlslProgram(vertexShaderId, fragmentShaderId, _programId))
	{
		printf("Could not link GLSL program!\n");
		return false;
	}

	//vertex VBO
	GLfloat triangleVertices[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
	};
	glGenBuffers(1, &_vboTriangle);
	glBindBuffer(GL_ARRAY_BUFFER, _vboTriangle);
	glBufferData(GL_ARRAY_BUFFER,
					static_cast<GLsizeiptr>(sizeof(triangleVertices)),
					triangleVertices,
					GL_STATIC_DRAW);

	return true;
}

void Tutorial4::Close()
{
	glDeleteProgram(_programId);
	glDeleteBuffers(1, &_vboTriangle);
}

void Tutorial4::HandleInput(SDL_Event)
{
	//do nothing
}

int Tutorial4::OpenGlMajorVersion()
{
	return 4;
}
	
int Tutorial4::OpenGlMinorVersion()
{
	return 0;
}

int Tutorial4::WindowHeight()
{
	return 600;
}

int Tutorial4::WindowWidth()
{
	return 800;
}

bool Tutorial4::IsQuit()
{
	return false;
}

