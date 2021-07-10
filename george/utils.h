#pragma once
#include <cstdint>
#include <cmath>
#include <algorithm>

#define M_PI 3.14159265358979323846


struct Colour32 {
	Colour32(std::uint8_t r = 0, std::uint8_t g = 0, std::uint8_t b = 0, std::uint8_t a =0);
	friend Colour32 operator+(const Colour32& c1, const Colour32& c2);

	std::uint32_t data;
};

struct Colour {
	double r, g, b, a;

	Colour(double red = 0.0, double green = 0.0, double blue = 0.0, double alpha = 0.0);
	Colour32 to_c32();
	friend Colour operator+(const Colour& c1, const Colour& c2);
	friend Colour operator*(const Colour& c1, const Colour& c2);

};





