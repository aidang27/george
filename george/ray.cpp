#include "ray.h"

sphere gaming{ 20, vec3{0, 0, -25}, dir3{} };
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
	vec3 ray{};

	for (int i = 0; i < 255; i++) {
		ray.x = position.x + len * direction.x;
		ray.y = position.y + len * direction.y;
		ray.z = position.z + len * direction.z;
		steps++;
		len = closestshape(ray, shapes);

		int value = std::clamp(255 * steps / 20, 0, 255);
		
		////static_cast<uint8_t>(value)
		if (len < 1) {
			std::cout << steps << "\n";
			return Colour{ 255,255,255, 40};
		}
	}

	return Colour{ 0,0,0,0 };
}