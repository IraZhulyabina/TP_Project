//
// Created by profidoc on 10.04.2022.
//

#pragma once
#include "include/BasicStructs/structs.h"

namespace kinematics {

const float kSecondsInMillisecond = 1e-3;

const float kMainCharacterVelocity = kSecondsInMillisecond * 30;

enum Orientation {
  Top,
  Right,
  Down,
  Left
};

const std::map<Orientation, Coord2f> velocities = {
    { Top, UnitVector(-90) },
    { Right, UnitVector(0) },
    { Down, UnitVector(90) },
    { Left, UnitVector(180) },
};

float FloatNegativeModuleDivision(float divisible, float divider);
Orientation AngleToOrientation(float angle);

}