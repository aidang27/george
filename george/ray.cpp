#include "ray.h"

double closestshape(pos& position, std::vector<shape>& list) {
	double dist = list[0].distance(position);

	for (auto shapes : list) {
		if (int x = shapes.distance(position) && x < dist) {
			dist = x;
		}
	}
	return dist;
}

Colour castray(ang& angle, pos& position){}