//
// Created by profidoc on 20.03.2022.
//

#include "include/Physics/PhysicalEntity.h"

const Rect2f& PhysicalEntity::GetPhysicalShape() const { return physical_shape_; }

void PhysicalEntity::SetPhysicalShape(const Rect2f& physical_shape) {
  physical_shape_ = physical_shape;
}

void PhysicalEntity::SetPhysicalPosition(const Coord2f& position) {
  physical_shape_.left = position.x;
  physical_shape_.top = position.y;
}

void PhysicalEntity::MovePhysical(const Coord2f& position) {
  physical_shape_.left += position.x;
  physical_shape_.top += position.y;
}

bool PhysicalEntity::Contains(Coord2f& point) {
  return physical_shape_.contains(point);
}

bool PhysicalEntity::Intersects(const PhysicalEntity& other) {
  return physical_shape_.intersects(other.physical_shape_);
}

float PhysicalEntity::GetSpeed() const { return speed_; }

const Coord2f& PhysicalEntity::GetVelocityDirection() const {
  return velocity_direction_;
}
void PhysicalEntity::SetVelocity(const Coord2f& velocity_dir) {
  float normalization_coefficient = Coord2fAbs(velocity_dir);
  if (normalization_coefficient == 0) {
    normalization_coefficient = 1;
  }
  velocity_direction_.x = velocity_dir.x / normalization_coefficient;
  velocity_direction_.y = velocity_dir.y / normalization_coefficient;
}
