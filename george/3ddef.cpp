#include "3ddef.h"

using namespace std;

vec3::vec3(double x, double y, double z)
	: x(x)
	, y(y)
	, z(z)
{
}

double vec3::dist(vec3& point) {
	return hypot(hypot(x - point.x, y - point.y), z - point.z);
}

vec3 operator+(const vec3& p1, const vec3& p2) {
	return vec3{ p1.x + p2.x, p1.y + p2.y, p1.z + p2.z };
}

vec3 operator-(const vec3& p1, const vec3& p2) {
	return vec3{ p1.x - p2.x, p1.y - p2.y, p1.z - p2.z };
}

void vec3::normalise() {
	float length_of_v = sqrt((x * x) + (y * y) + (z * z));
	x = x / length_of_v;
	y = y / length_of_v;
	z = z / length_of_v;
}

dir3::dir3(double p, double y, double r)
	: x(p)
	, y(y)
	, z(r)
{
}

dir3 operator+(const dir3& p1, const dir3& p2) {
	return dir3{ p1.x + p2.x, p1.y + p2.y, p1.z + p2.z };
}

dir3 operator-(const dir3& p1, const dir3& p2) {
	return dir3{ p1.x - p2.x, p1.y - p2.y, p1.z - p2.z };
}

camera::camera(double fov, Colour* texture, int width, int height, vec3 position = vec3{}, dir3 direction = dir3{})
	: dir3{ direction.x, direction.y, direction.z }
	, vec3{ position.x, position.y, position.z }
	, fov{ fov }
	, width(width)
	, height(height)
	, texture(texture)
{
	setup();
}

/*
	Most of this code from:
	https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays
*/
void camera::setup() {
	aspectratio = (double)width / (double)height;
	double scale = tan(deg2rad(fov / 2));
	vec3 origin{};
	camerarays = std::vector<std::vector<vec3>>( width, std::vector<vec3>(height, vec3{}) );

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			//Change the rasterspace coordinates to worldspace coordinates
			double xval = (2 * (x + 0.5) / (double)width - 1) * aspectratio * scale;
			double yval = (1 - 2 * (y + 0.5) / (double)height) * scale;

			//Compose the direction assuming that the camera is positioned at 0, 0, 0 and is pointing towards the negative z direction
			camerarays[x][y] = vec3{ xval, yval, -1.0 };
			camerarays[x][y].normalise();
		}
	}

}

double deg2rad(double deg) {
	return deg * M_PI / 180.0;
}
