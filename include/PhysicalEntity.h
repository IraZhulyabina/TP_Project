//
// Created by profidoc on 04.05.22.
//

#pragma once
#include "BasicEntity.h"
#include "structs/Rect.h"
#include "structs/Vector2.h"

class PhysicalEntity: public BasicEntity {
 public:
  PhysicalEntity() = default;
  PhysicalEntity(const Rect2f& physical_rect);

  float GetSpeed() const;
  const Vector2f& GetVelocityDirection() const;
  const Rect2f& GetPhysicalRect() const;
  void SetSpeed(float speed);
  void SetVelocityDirection(const Vector2f& velocity_direction);
  void SetPhysicalShape(const Vector2i& shape);
  void SetID(uint64_t id);
  uint64_t GetID();

 protected:
  void MovePhysical(const Vector2f& shift);
  void SetPhysicalPosition(const Vector2f& position);
  uint64_t id_;
  Rect2f physical_rect_;
  float speed_ = 0;
  Vector2f velocity_direction_ = {0, 0};
};
