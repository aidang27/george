#include "shape.h"

shape::shape(vec3 position, vec3 direction)
	: pos{position.x, position.y, position.z}
	, dir{direction.x, direction.y, direction.z}
{
}

sphere::sphere(double radius, vec3 position, vec3 direction)
	: shape{ position, direction }
	, radius(radius)
{
}

double shape::distance(vec3& postion) {
	return 0.0;
}

double sphere::distance(vec3& position){
	return pos.dist(position) - radius;
}
