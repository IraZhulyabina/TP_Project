//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include "include/BasicStructs/structs.h"

class Entity {
 public:
  Entity() = default;
  explicit Entity(const Coord2f& position);
  Coord2f& GetPosition();
  virtual void SetPosition(const Coord2f& position) = 0;
  virtual void Move(const Coord2f& delta) = 0;

 protected:
  Coord2f position_ = {0, 0};
};