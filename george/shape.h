#pragma once
#include "3ddef.h"

class shape {
protected:
	vec3 pos, dir;
public:
	shape(vec3 position, vec3 direction);
	virtual double distance(vec3& position);
};

class sphere : public shape {
public:
	double radius;
	sphere(double radius, vec3 position, vec3 direction);
	double distance(vec3& position) override;
};