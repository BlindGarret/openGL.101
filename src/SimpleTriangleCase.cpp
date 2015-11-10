#include "SimpleTriangleCase.h"
#include <fstream>
#include <iterator>
#include <vector>
#include <iostream>

void SimpleTriangleCase::Render()
{
	glClear( GL_COLOR_BUFFER_BIT );

	glUseProgram(_programId);
	glEnableVertexAttribArray(static_cast<GLuint>(_attributeCoord2d));

	GLfloat triangleVertices[] = {
		0.0,0.8,
		-0.8,-0.8,
		0.8,-0.8
	};

	glVertexAttribPointer(static_cast<GLuint>(_attributeCoord2d),
							 2,
							 GL_FLOAT,
							 GL_FALSE,
							 0,
							 triangleVertices);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(static_cast<GLuint>(_attributeCoord2d));
}

bool SimpleTriangleCase::Init()
{
	glClearColor( 0.0f, 0.0f, 1.0f, 1.0f );

	//Load shader from file SimpleVertexShader
	std::ifstream vertexInput("shaders/SimpleVertexShader.vs");
	if(!vertexInput.good())
	{
		printf("Could not open vertex file!\n");
		return false;
	}

	const char* vertexShader = std::string(std::istreambuf_iterator<char>(vertexInput),
								 std::istreambuf_iterator<char>())
								.c_str();

	GLuint vertexShaderId;
	if(!TryCompileShader(vertexShader, GL_VERTEX_SHADER, vertexShaderId))
	{
		return false;
	}

	std::ifstream fragmentInput("shaders/SimpleFragmentShader.fs");

	if(!fragmentInput.good())
	{
		printf("Could not open fragment file!\n");
		return false;
	}

	const char* fragmentShader = std::string(std::istreambuf_iterator<char>(fragmentInput),
								 std::istreambuf_iterator<char>())
								.c_str();

	GLuint fragmentShaderId;
	if(!TryCompileShader(fragmentShader, GL_FRAGMENT_SHADER, fragmentShaderId))
	{
		return false;
	}

	if(!TryLinkGlslProgram(vertexShaderId, fragmentShaderId, _programId))
	{
		return false;
	}

	const GLchar* attributeName = "coord2d";
	_attributeCoord2d = glGetAttribLocation(_programId, attributeName);
	if(_attributeCoord2d == -1)
	{
		printf("Could not Bind Attribute!");
		return false;
	}

	return true;
}

void SimpleTriangleCase::Close()
{
	glDeleteProgram(_programId);
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

bool SimpleTriangleCase::TryCompileShader(const char* shader, GLenum shaderType, GLuint& outshaderId)
{
	outshaderId = glCreateShader(shaderType);
	glShaderSource(outshaderId, 1, &shader, nullptr);
	glCompileShader(outshaderId);
	GLint compiled = GL_FALSE;
	glGetShaderiv(outshaderId, GL_COMPILE_STATUS, &compiled);
	if(!compiled)
	{
		GLint logSize = 0;
		glGetShaderiv(outshaderId, GL_INFO_LOG_LENGTH, &logSize);
		std::vector<GLchar> errorLog(static_cast<GLuint>(logSize));
		glGetShaderInfoLog(outshaderId, logSize, &logSize, &errorLog[0]);
		std::string output;
		for(auto c : errorLog)
		{
			output += c;
		}
		printf("Unabled to Compile Shader!\n");
		std::cout << output;
		return false;
	}
	return true;
}


bool SimpleTriangleCase::TryLinkGlslProgram(GLuint vertexShaderId, GLuint fragmentShaderId, GLuint& outProgramId)
{
	outProgramId = glCreateProgram();
	glAttachShader(outProgramId, vertexShaderId);
	glAttachShader(outProgramId, fragmentShaderId);
	glLinkProgram(outProgramId);
	GLint linked = GL_FALSE;
	glGetProgramiv(outProgramId, GL_LINK_STATUS, &linked);
	if(!linked)
	{
		GLint logSize = 0;
		glGetProgramiv(outProgramId, GL_INFO_LOG_LENGTH, &logSize);
		std::vector<GLchar> errorLog(static_cast<GLuint>(logSize));
		glGetProgramInfoLog(outProgramId, logSize, &logSize, &errorLog[0]);
		std::string output;
		for(auto c : errorLog)
		{
			output += c;
		}
		printf("Unabled to link GLSL program!\n");
		std::cout << output;
		return false;
	}
	return true;
}

