#include "ray.h"

sphere gaming{ 20, vec3{0, 60, -250}, vec3{} };
sphere burger{ 40, vec3{0, -60, -250}, vec3{} };
std::vector<shape*> shapes{ &gaming, &burger };

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

Colour32 castray(vec3& direction, vec3& position){
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
			return Colour{1.0, 1.0, 1.0, 1.0}.to_c32();
		}
	}

	return Colour32{ 0,0,0,0 };
}