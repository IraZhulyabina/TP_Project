//
// Created by profidoc on 11.04.2022.
//

#include "resources/headers/Kinematics.h"
#include "iostream"

kinematics::Orientation kinematics::AngleToOrientation(float angle) {
  angle = FloatModule(angle, 360);
  angle += 45;

  if (angle <= 90) {
    return Right;
  }
  if (angle <= 145) {
    return Down;
  }
  if (angle <= 270) {
    return Left;
  }
  if (angle <= 315) {
    return Up;
  }
  if (angle <= 360) {
    return Right;
  }
  return Stay;
}