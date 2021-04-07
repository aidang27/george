#pragma once
#include <cmath>
#include <algorithm>

class pos {
public:
	double x, y, z;

	pos(double x = 0.0, double y = 0.0, double z = 0.0);
	double dist(pos& point);
};

pos operator+(const pos& p1, const pos& p2);
pos operator-(const pos& p1, const pos& p2);


class ang {
public:
	double p, y, r;

	ang(double p = 0.0, double y = 0.0, double r = 0.0);
};

ang operator+(const ang& a1, const ang& a2);
ang operator-(const ang& a1, const ang& a2);

class camera : public ang, public pos {
public:
	double fov;

	camera(double fov, pos position, ang angle);
};