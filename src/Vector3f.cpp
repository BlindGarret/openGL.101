#include "Vector3f.h"

Vector3f::Vector3f(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
}

Vector3f::Vector3f(GLfloat x, GLfloat y, GLfloat z)
{
	_x = static_cast<float>(x);
	_y = static_cast<float>(y);
	_z = static_cast<float>(z);
}

float Vector3f::X()
{
	return _x;
}

float Vector3f::Y()
{
	return _y;
}

float Vector3f::Z()
{
	return _z;
}

GLfloat Vector3f::GlX()
{
	return static_cast<GLfloat>(_x);
}

GLfloat Vector3f::GlY()
{
	return static_cast<GLfloat>(_y);
}

GLfloat Vector3f::GlZ()
{
	return static_cast<GLfloat>(_z);
}

