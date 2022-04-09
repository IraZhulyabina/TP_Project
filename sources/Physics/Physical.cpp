//
// Created by profidoc on 20.03.2022.
//

#include "include/Physics/Physical.h"

const Rect2f& Physical::GetPhysicalShape() const { return physical_shape_; }

void Physical::SetPhysicalShape(const Rect2f& physical_shape) {
  physical_shape_ = physical_shape;
}

void Physical::SetPosition(const Coord2f& position) {
  physical_shape_.left = position.x;
  physical_shape_.top = position.y;
}

void Physical::Move(const Coord2f& position) {
  physical_shape_.left += position.x;
  physical_shape_.top += position.y;
}

bool Physical::Contains(Coord2f& point) {
  return physical_shape_.contains(point);
}

bool Physical::Intersects(const Physical& other) {
  return physical_shape_.intersects(other.physical_shape_);
}
