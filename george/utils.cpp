#include "utils.h"

Colour32::Colour32(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) {
	data = (a) | (b << 8) | (g << 16) | (r << 24);
}

Colour32 operator+(const Colour32 &c1, const Colour32 &c2) {
	Colour32 ret{ 0,0,0,0 };
	ret.data = c1.data | c2.data;
	return ret;
}

Colour::Colour(double red, double green, double blue, double alpha) {
	r = std::clamp(red, 0.0, 1.0);
	g = std::clamp(green, 0.0, 1.0);
	b = std::clamp(blue, 0.0, 1.0);
	a = std::clamp(alpha, 0.0, 1.0);
}

Colour operator+(const Colour& c1, const Colour& c2) {
	Colour ret{};

	ret.r = std::clamp(c1.r + c2.r, 0.0, 1.0);
	ret.g = std::clamp(c1.g + c2.g, 0.0, 1.0);
	ret.b = std::clamp(c1.b + c2.b, 0.0, 1.0);
	ret.a = std::clamp(c1.a + c2.a, 0.0, 1.0);

	return ret;
}

Colour operator*(const Colour& c1, const Colour& c2) {
	Colour ret{};

	ret.r = std::clamp(c1.r * c2.r, 0.0, 1.0);
	ret.g = std::clamp(c1.g * c2.g, 0.0, 1.0);
	ret.b = std::clamp(c1.b * c2.b, 0.0, 1.0);
	ret.a = std::clamp(c1.a * c2.a, 0.0, 1.0);

	return ret;
}

Colour32 Colour::to_c32() {
	Colour32 ret;

	ret.data = (static_cast<std::uint32_t>(255 * a)) << 0;
	ret.data = (static_cast<std::uint32_t>(255 * b)) << 8;
	ret.data = (static_cast<std::uint32_t>(255 * g)) << 16;
	ret.data = (static_cast<std::uint32_t>(255 * r)) << 24;

	return ret;
}