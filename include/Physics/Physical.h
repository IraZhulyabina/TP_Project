//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include "include/main.h"

class Physical {
 public:
  const Rect2f& GetPhysicalShape() const;
  void SetPhysicalShape(const Rect2f& physical_shape);
  void SetPosition(const Coord2f& position);
  void Move(const Coord2f& position);
  bool Contains(Coord2f& point);
  bool Intersects(const Physical& other);
  // TODO: intersection with strait line

 protected:
  Rect2f physical_shape_;  // TODO: non-rectangle objects?
};
