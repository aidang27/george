#include "3ddef.h"

using namespace std;

vec3::vec3(double x, double y, double z)
	: x(x)
	, y(y)
	, z(z)
{
}

double vec3::dist(vec3& point) {
	return sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
}

vec3 operator+(const vec3& p1, const vec3& p2) {
	return vec3{ p1.x + p2.x, p1.y + p2.y, p1.z + p2.z };
}

vec3 operator-(const vec3& p1, const vec3& p2) {
	return vec3{ p1.x - p2.x, p1.y - p2.y, p1.z - p2.z };
}

dir3::dir3(double p, double y, double r)
	: x(p)
	, y(y)
	, z(r)
{
}

dir3 operator+(const dir3& p1, const dir3& p2) {
	return dir3{ p1.x + p2.x, p1.y + p2.y, p1.z + p2.z };
}

dir3 operator-(const dir3& p1, const dir3& p2) {
	return dir3{ p1.x - p2.x, p1.y - p2.y, p1.z - p2.z };
}

camera::camera(double fov, vec3 position, dir3 direction)
	: dir3{ direction.x, direction.y, direction.z }
	, vec3{ position.x, position.y, position.z }
	, fov{ fov }
{
}
