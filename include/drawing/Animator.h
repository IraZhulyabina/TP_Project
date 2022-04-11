//
// Created by profidoc on 11.04.2022.
//

#pragma once
#include "include/drawing/TileSet.h"
#include "SFML/System/Clock.hpp"

class Animator : TileSet {
 public:
  Animator() = default;
  Animator(const Rect2u& sub_table, float frames_per_second);
  void UpdateFrame(float delta_time);

 private:
  float frames_per_second_ = 0;
  float elapsed_time_ = 0;
};
