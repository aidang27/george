#include "shape.h"

shape::shape(pos position, ang angle)
	: pos{position.x, position.y, position.z}
	, ang{angle.p, angle.y, angle.r}
{
}

sphere::sphere(double radius, pos position, ang angle)
	: shape{ position, angle }
	, radius(radius)
{
}

double sphere::distance(pos& position) {
	return dist(position) - radius;
}
