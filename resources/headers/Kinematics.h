//
// Created by profidoc on 10.04.2022.
//

#pragma once
#include "include/BasicStructs/structs.h"

namespace kinematics {

const float kSecondsInMillisecond = 1e-3;
const float kMilliSecondsInSecond = 1e3;

enum Orientation { Stay, Down, Left, Right, Up };


Orientation AngleToOrientation(float angle);

}  // namespace kinematics