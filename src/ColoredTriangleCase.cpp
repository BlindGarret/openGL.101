#include "ColoredTriangleCase.h"
#include "ShaderHelper.h"
#include <cstdio>
#include <string>

void ColoredTriangleCase::Render()
{
	glClear( GL_COLOR_BUFFER_BIT );

	glUseProgram(_programId);
	glEnableVertexAttribArray(static_cast<GLuint>(_attributeCoord2d));
	glEnableVertexAttribArray(static_cast<GLuint>(_attributeVertexColor));
	glBindBuffer(GL_ARRAY_BUFFER, _vboTriangle);
	glVertexAttribPointer(static_cast<GLuint>(_attributeCoord2d),
							 2,
							 GL_FLOAT,
							 GL_FALSE,
							 0,
							 0);
	glBindBuffer(GL_ARRAY_BUFFER, _vboTriangleColors);
	glVertexAttribPointer(static_cast<GLuint>(_attributeVertexColor),
							 3,
							 GL_FLOAT,
							 GL_FALSE,
							 0,
							 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(static_cast<GLuint>(_attributeCoord2d));
	glDisableVertexAttribArray(static_cast<GLuint>(_attributeVertexColor));
}

bool ColoredTriangleCase::Init()
{
	if(!GLEW_VERSION_2_0)
	{
		printf("This computer cannot support required OpenGL version 2.0!\n");
		return false;
	}

	glClearColor( 0.0f, 0.0f, 1.0f, 1.0f );
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	auto shaderHelper = ShaderHelper();

	//vertex shader
	std::string vertexShader = "";

	if(!shaderHelper.TryReadShaderFile("shaders/PreColoredVertexShader.vs", vertexShader))
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
	if(!shaderHelper.TryReadShaderFile("shaders/PreColoredFragmentShader.fs", fragmentShader))
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
		0.0, 0.8,
		-0.8, -0.8,
		0.8, -0.8
	};
	glGenBuffers(1, &_vboTriangle);
	glBindBuffer(GL_ARRAY_BUFFER, _vboTriangle);
	glBufferData(GL_ARRAY_BUFFER,
					static_cast<GLsizeiptr>(sizeof(triangleVertices)),
					triangleVertices,
					GL_STATIC_DRAW);

	//Color VBO
	GLfloat triangleColors[] = {
		1.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
		1.0, 0.0, 0.0,
	};
	glGenBuffers(1, &_vboTriangleColors);
	glBindBuffer(GL_ARRAY_BUFFER, _vboTriangleColors);
	glBufferData(GL_ARRAY_BUFFER,
	             static_cast<GLsizeiptr>(sizeof(triangleColors)),
	             triangleColors,
	             GL_STATIC_DRAW);


	const GLchar* attributeName = "coord2d";
	_attributeCoord2d = glGetAttribLocation(_programId, attributeName);
	if(_attributeCoord2d == -1)
	{
		printf("Could not Bind Attribute %s!\n", attributeName);
		return false;
	}

	attributeName = "vertexColor";
	_attributeVertexColor = glGetAttribLocation(_programId, attributeName);

	if(_attributeVertexColor == -1)
	{
		printf("Could not Bind Attribute %s!\n", attributeName);
		return false;
	}

	return true;
}

void ColoredTriangleCase::Close()
{
	glDeleteProgram(_programId);
	glDeleteBuffers(1, &_vboTriangle);
}

void ColoredTriangleCase::HandleInput(SDL_Event)
{
	//do nothing
}

int ColoredTriangleCase::OpenGlMajorVersion()
{
	return 2;
}
	
int ColoredTriangleCase::OpenGlMinorVersion()
{
	return 1;
}

int ColoredTriangleCase::WindowHeight()
{
	return 600;
}

int ColoredTriangleCase::WindowWidth()
{
	return 800;
}

bool ColoredTriangleCase::IsQuit()
{
	return false;
}

