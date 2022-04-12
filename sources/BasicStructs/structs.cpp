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

bool AreCounterclockwise(Coord2f& first_point, Coord2f& second_point,
                         Coord2f& third_point) {
  return (second_point.y - first_point.y) * (third_point.x - first_point.x) <
         (third_point.y - first_point.y) * (second_point.x - first_point.x);
}

bool Segment::Intersects(Segment& other) {
  bool are_in_different_order_first = AreCounterclockwise(
                                          top_left_position_,
                                          other.top_left_position_,
                                          other.bottom_right_position_) !=
                                      AreCounterclockwise(
                                          bottom_right_position_,
                                          other.top_left_position_,
                                          other.bottom_right_position_);
  bool are_in_different_order_second = AreCounterclockwise(
                                           top_left_position_,
                                           bottom_right_position_,
                                           other.top_left_position_) !=
                                       AreCounterclockwise(
                                           bottom_right_position_,
                                           bottom_right_position_,
                                           other.bottom_right_position_);
  return are_in_different_order_first && are_in_different_order_second;
}
