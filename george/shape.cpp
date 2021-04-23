#include "shape.h"

shape::shape(vec3 position, dir3 angle)
	: vec3{position.x, position.y, position.z}
	, dir3{angle.x, angle.y, angle.z}
{
}

sphere::sphere(double radius, vec3 position, dir3 direction)
	: shape{ position, direction }
	, radius(radius)
{
}

double shape::distance(vec3& postion) {
	return 0.0;
}

double sphere::distance(vec3& position){
	return this->dist(position) - radius;
}
