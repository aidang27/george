#pragma once
#include "3ddef.h"

class shape : public vec3, public dir3 {
public:
	shape(vec3 position, dir3 direction);
	virtual double distance(vec3& position);
};

class sphere : public shape {
public:
	double radius;
	sphere(double radius, vec3 position, dir3 direction);
	virtual double distance(vec3& position);
};