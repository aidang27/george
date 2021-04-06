#include "3ddef.h"

using namespace std;

pos::pos(double x, double y, double z)
	: x(x)
	, y(y)
	, z(z)
{
}

double pos::dist(pos& point) {
	return sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
}

pos operator+(const pos& p1, const pos& p2) {
	return pos{ p1.x + p2.x, p1.y + p2.y, p1.z + p2.z };
}

pos operator-(const pos& p1, const pos& p2) {
	return pos{ p1.x - p2.x, p1.y - p2.y, p1.z - p2.z };
}

ang::ang(double p, double y, double r)
	: p(p)
	, y(y)
	, r(r)
{
}

ang operator+(const ang& a1, const ang& a2) {
	return ang{ clamp(a1.p + a2.p ,0.0 ,360.0), clamp(a1.y + a2.y ,0.0 ,360.0), clamp(a1.r + a2.r ,0.0 ,360.0)};
}

ang operator-(const ang& a1, const ang& a2) {
	return ang{ clamp(a1.p - a2.p ,0.0 ,360.0), clamp(a1.y - a2.y ,0.0 ,360.0), clamp(a1.r - a2.r ,0.0 ,360.0) };
}

