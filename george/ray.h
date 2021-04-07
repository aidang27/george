#pragma once
#include "3ddef.h"
#include "utils.h"
#include "shape.h"
#include <vector>

double closestshape(vec3& position, std::vector<shape>& list);
Colour castray(dir3& direction, vec3& position);