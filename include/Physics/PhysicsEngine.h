//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include <vector>
#include "include/Physics/PhysicalEntity.h"
#include "include/Entities/Entity.h"

class PhysicsEngine {
 public:
  void AddTarget(PhysicalEntity* target);
  void ProcessVelocities(float frame_time);

 private:
  std::vector<PhysicalEntity*> targets_;
};
