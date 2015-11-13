#include "Vector3f.h"

Vector3f::Vector3f(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
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

