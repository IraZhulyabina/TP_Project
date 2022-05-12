//
// Created by profidoc on 04.05.22.
//

#pragma once
#include "structs/Vector2.h"

class BasicEntity {
 public:
  virtual void SetPosition(const Vector2f& position) = 0;
  virtual void Move(const Vector2f& shift) = 0;

 private:
  Vector2f position_;
};
