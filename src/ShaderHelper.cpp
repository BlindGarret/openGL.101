#include "ShaderHelper.h"
#include <fstream>
#include <iterator>
#include <vector>
#include <iostream>

bool ShaderHelper::TryReadShaderFile(const char* path, const char*& output)
{
	//Load shader from file SimpleVertexShader
	std::ifstream input(path);
	if(!input.good())
	{	
		output = "";
		return false;
	}

	output = std::string(std::istreambuf_iterator<char>(input),
								 std::istreambuf_iterator<char>())
								.c_str();
	return true;
}

bool ShaderHelper::TryCompileVertexShader(const char* shader, GLuint& outshaderId)
{
	return TryCompileShader(shader, GL_VERTEX_SHADER, outshaderId);
}

bool ShaderHelper::TryCompileFragmentShader(const char* shader, GLuint& outshaderId)
{
	return TryCompileShader(shader, GL_FRAGMENT_SHADER, outshaderId);
}

bool ShaderHelper::TryLinkGlslProgram(GLuint vertexShaderId, GLuint fragmentShaderId, GLuint& outProgramId)
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

bool ShaderHelper::TryCompileShader(const char* shader, GLenum shaderType, GLuint& outshaderId)
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
