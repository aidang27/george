#include "ray.h"

sphere gaming{ 20, vec3{0, 10, -25}, dir3{} };
std::vector<shape*> shapes{ &gaming };

double closestshape(vec3& position, std::vector<shape*>& list) {
	double dist = list[0]->distance(position);

	for (auto *shapes : list) {
		double x = shapes->distance(position);
		if (x < dist) {
			dist = x;
		}
	}
	return dist;
}

Colour castray(vec3& direction, vec3& position){
	double len = closestshape(position, shapes);
	int steps = 0;

	vec3 ray{position};
	for (int i = 0; i < 50; i++) {
		ray.x += len * direction.x;
		ray.y += len * direction.y;
		ray.z += len * direction.z;
		steps++;

		len = closestshape(ray, shapes);

		if (len < 0.0000001) {
			return Colour{ 255,255,255, 255 };
		}
	}

	return Colour{ 0,0,0,0 };
}