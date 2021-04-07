#include "ray.h"

double closestshape(vec3& position, std::vector<shape>& list) {
	double dist = list[0].distance(position);

	for (auto shapes : list) {
		double x = shapes.distance(position);
		if (x < dist) {
			dist = x;
		}
	}
	return dist;
}

Colour castray(dir3& direction, vec3& position){
	return Colour{ 0,0,0,0 };
}