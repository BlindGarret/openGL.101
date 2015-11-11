#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/glu.h>
#include <string>

class ShaderHelper
{
public:
	bool TryReadShaderFile(std::string path, std::string& output);
	bool TryCompileVertexShader(std::string shader, GLuint& outshaderId);
	bool TryCompileFragmentShader(std::string shader, GLuint& outshaderId);
	bool TryLinkGlslProgram(GLuint vertexShaderId, GLuint fragmentShaderId, GLuint& outProgramId);
private:
	bool TryCompileShader(std::string shader, GLenum shaderType, GLuint& outshaderId);
};
