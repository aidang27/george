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

class camera {
public:
	double fov;
	int width, height;
	double aspectratio;
	vec3 pos, dir;
	std::vector<std::vector<vec3>> camerarays;

	camera(double fov, Colour32* texture, int width, int height, vec3 position, vec3 direction);
	void setup();
private:
	Colour32* texture;
};

double deg2rad(double deg);



