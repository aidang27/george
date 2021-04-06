#pragma once
#include <cmath>
#include <algorithm>

class pos {
public:
	double x, y, z;

	pos(double x, double y, double z);
	double dist(pos& point);
};

pos operator+(const pos& p1, const pos& p2);
pos operator-(const pos& p1, const pos& p2);


class ang {
public:
	double p, y, r;

	ang(double p, double y, double r);
};

ang operator+(const ang& a1, const ang& a2);
ang operator-(const ang& a1, const ang& a2);