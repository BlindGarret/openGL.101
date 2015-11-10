#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/glu.h>

class ShaderHelper
{
public:
	bool TryReadShaderFile(const char* path, const char*& output);
	bool TryCompileVertexShader(const char* shader, GLuint& outshaderId);
	bool TryCompileFragmentShader(const char* shader, GLuint& outshaderId);
	bool TryLinkGlslProgram(GLuint vertexShaderId, GLuint fragmentShaderId, GLuint& outProgramId);
private:
	bool TryCompileShader(const char* shader, GLenum shaderType, GLuint& outshaderId);
};
