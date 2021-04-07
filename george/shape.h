#pragma once
#include "3ddef.h"

class shape : public pos, public ang {
public:
	shape(pos position, ang angle);
	virtual double distance(pos& position);
};

class sphere : public shape {
public:
	double radius;
	sphere(double radius, pos position, ang angle);
	virtual double distance(pos& position);
};