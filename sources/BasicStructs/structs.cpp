//
// Created by profidoc on 11.04.2022.
//

#include "include/BasicStructs/structs.h"

float Coord2fAbs(const Coord2f& vect) {
  return sqrt(vect.x * vect.x + vect.y * vect.y);
}

float Rad(float angle) {
  return (angle / 180.0) * M_PI;
}

Coord2f UnitVector(float angle) {  // angle in degrees
  return {cos(Rad(angle)), sin(Rad(angle))};
}
