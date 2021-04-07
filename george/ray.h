#pragma once
#include "3ddef.h"
#include "utils.h"
#include "shape.h"
#include <vector>

double closestshape(pos& position, std::vector<shape>& list);
Colour castray(ang& angle, pos& position);