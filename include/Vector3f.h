#ifndef VECTOR3F_HEADER
#define VECTOR3F_HEADER
#include <GL/gl.h>

struct Vector3f
{
public:
	Vector3f(float x, float y, float z);
	float X();
	float Y();
	float Z();
private:
	float _x;
	float _y;
	float _z;
};

#endif
