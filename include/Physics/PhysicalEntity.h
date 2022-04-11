//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include "include/BasicStructs/structs.h"
#include "include/Entities/Entity.h"
#include <math.h>

class PhysicalEntity : public Entity {
 public:
  const Rect2f& GetPhysicalShape() const;
  void SetPhysicalShape(const Rect2f& physical_shape);
  bool Contains(Coord2f& point);
  bool Intersects(const PhysicalEntity& other);
  float GetSpeed() const;
  const Coord2f & GetVelocityDirection() const;

 protected:
  void MovePhysical(const Coord2f& position);
  void SetPhysicalPosition(const Coord2f& position);
  Rect2f physical_shape_;  // TODO: non-rectangle objects?
  float speed_ = 0;
  float acceleration_ = 0;
  Coord2f velocity_direction_ = {0, 0};  // normal vector
  Coord2f acceleration_direction_ = {0, 0};  // normal vector
};
