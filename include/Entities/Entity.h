//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include "include/main.h"

class Entity {
 public:
  Entity() = default;
  explicit Entity(const Coord2f& position);

 protected:
  Coord2f position_ = {0, 0};
};
