#pragma once
#include <cmath>
#include <algorithm>

class vec3 {
public:
	double x, y, z;

	vec3(double x = 0.0, double y = 0.0, double z = 0.0);
	double dist(vec3& point);
};

vec3 operator+(const vec3& p1, const vec3& p2);
vec3 operator-(const vec3& p1, const vec3& p2);


class dir3 {
public:
	double x, y, z;

	dir3(double x = 0.0, double y = 0.0, double z = 0.0);
};

dir3 operator+(const dir3& p1, const dir3& p2);
dir3 operator-(const dir3& p1, const dir3& p2);

class camera : public dir3, public vec3 {
public:
	double fov;

	camera(double fov, vec3 position, dir3 direction);
};