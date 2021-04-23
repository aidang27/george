#pragma once
#include <cmath>
#include <algorithm>
#include "utils.h"
#include <vector>

class vec3 {
public:
	double x, y, z;

	vec3(double x = 0.0, double y = 0.0, double z = 0.0);
	void normalise();
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
	int width, height;
	double aspectratio;
	std::vector<std::vector<vec3>> camerarays;

	camera(double fov, Colour* texture, int width, int height, vec3 position, dir3 direction);
	void setup();
private:
	Colour* texture;
};

double deg2rad(double deg);



