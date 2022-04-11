//
// Created by profidoc on 11.04.2022.
//

#include "resources/headers/Kinematics.h"

kinematics::Orientation kinematics::AngleToOrientation(float angle) {
  angle = FloatNegativeModuleDivision(angle, 360);
  angle = FloatNegativeModuleDivision(angle + 360,360);
  angle += 45;

  if (angle <= 90) {
    return Down;
  }
  if (angle <= 180) {
    return Left;
  }
  if (angle <= 270) {
    return Top;
  }
  return Right;
}
float kinematics::FloatNegativeModuleDivision(float divisible, float divider) {
  return divisible - static_cast<int>(divisible / divider) * divider;
}
