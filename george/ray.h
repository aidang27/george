#pragma once
#include "3ddef.h"
#include "utils.h"
#include "shape.h"
#include <vector>
#include <iostream>
double closestshape(vec3& position, std::vector<shape*>& list);
Colour castray(vec3& direction, vec3& position);