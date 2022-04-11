//
// Created by profidoc on 20.03.2022.
//

#include "include/Physics/PhysicsEngine.h"

void PhysicsEngine::ProcessVelocities(float frame_time) {
  for (PhysicalEntity* target : targets_) {
    target->Move(target->GetVelocityDirection() * target->GetSpeed() *
                 frame_time);
  }
}

void PhysicsEngine::AddTarget(PhysicalEntity* target) {
  targets_.push_back(target);
}
