//
// Created by profidoc on 04.05.22.
//

#include "PhysicalEntity.h"
void PhysicalEntity::SetPhysicalPosition(const Vector2f& position) {
  physical_rect_.left = position.x + 12;
  physical_rect_.top = position.y + 12;
}

void PhysicalEntity::MovePhysical(const Vector2f& shift) {
  physical_rect_ += shift;
}

float PhysicalEntity::GetSpeed() const { return speed_; }

const Vector2f& PhysicalEntity::GetVelocityDirection() const {
  return velocity_direction_;
}

const Rect2f& PhysicalEntity::GetPhysicalRect() const { return physical_rect_; }

void PhysicalEntity::SetSpeed(float speed) { speed_ = speed; }

void PhysicalEntity::SetVelocityDirection(const Vector2f& velocity_direction) {
  velocity_direction_ = velocity_direction;
}

void PhysicalEntity::SetPhysicalShape(const Vector2i& shape) {
  physical_rect_.width = shape.x - 24;
  physical_rect_.height = shape.y - 24;
}

PhysicalEntity::PhysicalEntity(const Rect2f& physical_rect)
    : physical_rect_(physical_rect) {}

void PhysicalEntity::SetID(uint64_t id) { id_ = id; }

uint64_t PhysicalEntity::GetID() { return id_; }
