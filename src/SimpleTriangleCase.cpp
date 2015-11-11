#include "SimpleTriangleCase.h"
#include "ShaderHelper.h"
#include <cstdio>
#include <string>

void SimpleTriangleCase::Render()
{
	glClear( GL_COLOR_BUFFER_BIT );

	glUseProgram(_programId);
	glBindBuffer(GL_ARRAY_BUFFER, _vboTriangle);
	glEnableVertexAttribArray(static_cast<GLuint>(_attributeCoord2d));
	glVertexAttribPointer(static_cast<GLuint>(_attributeCoord2d),
							 2,
							 GL_FLOAT,
							 GL_FALSE,
							 0,
							 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(static_cast<GLuint>(_attributeCoord2d));
}

bool SimpleTriangleCase::Init()
{
	if(!GLEW_VERSION_2_0)
	{
		printf("This computer cannot support required OpenGL version 2.0!");
		return false;
	}

	glClearColor( 0.0f, 0.0f, 1.0f, 1.0f );
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	auto shaderHelper = ShaderHelper();

	//vertex shader
	std::string vertexShader = "";

	if(!shaderHelper.TryReadShaderFile("shaders/SimpleVertexShader.vs", vertexShader))
	{
		printf("Could not open vertex file!\n");
		return false;
	}

	GLuint vertexShaderId;
	if(!shaderHelper.TryCompileVertexShader(vertexShader, vertexShaderId))
	{
		printf("Could not compile vertex shader!");
		return false;
	}

	//fragment shader
	std::string fragmentShader = "";
	if(!shaderHelper.TryReadShaderFile("shaders/SimpleFragmentShader.fs", fragmentShader))
	{
		printf("Could not open fragment file!\n");
		return false;
	}

	GLuint fragmentShaderId;
	if(!shaderHelper.TryCompileFragmentShader(fragmentShader, fragmentShaderId))
	{
		printf("Could not compile fragment shader!");
		return false;
	}

	//link program
	if(!shaderHelper.TryLinkGlslProgram(vertexShaderId, fragmentShaderId, _programId))
	{
		printf("Could not link GLSL program!");
		return false;
	}

	const GLchar* attributeName = "coord2d";
	_attributeCoord2d = glGetAttribLocation(_programId, attributeName);
	if(_attributeCoord2d == -1)
	{
		printf("Could not Bind Attribute!");
		return false;
	}

	GLfloat triangleVertices[] = {
		0.0,0.8,
		-0.8,-0.8,
		0.8,-0.8
	};
	glGenBuffers(1, &_vboTriangle);
	glBindBuffer(GL_ARRAY_BUFFER, _vboTriangle);
	glBufferData(GL_ARRAY_BUFFER,
					static_cast<GLsizeiptr>(sizeof(triangleVertices)),
					triangleVertices,
					GL_STATIC_DRAW);

	return true;
}

void SimpleTriangleCase::Close()
{
	glDeleteProgram(_programId);
	glDeleteBuffers(1, &_vboTriangle);
}

void SimpleTriangleCase::HandleInput(SDL_Event)
{
	//do nothing
}

int SimpleTriangleCase::OpenGlMajorVersion()
{
	return 2;
}
	
int SimpleTriangleCase::OpenGlMinorVersion()
{
	return 1;
}

int SimpleTriangleCase::WindowHeight()
{
	return 600;
}

int SimpleTriangleCase::WindowWidth()
{
	return 800;
}

bool SimpleTriangleCase::IsQuit()
{
	return false;
}

