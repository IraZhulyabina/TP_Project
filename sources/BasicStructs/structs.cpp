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

float Degrees(float angle) {
  return (angle / M_PI) * 180.0;
}

Coord2f UnitVector(float angle) {  // angle in degrees
  return {cos(Rad(angle)), sin(Rad(angle))};
}
float GetAngle(const Coord2f& vect) {
  return Degrees(asin(vect.y / Coord2fAbs(vect)));
}
