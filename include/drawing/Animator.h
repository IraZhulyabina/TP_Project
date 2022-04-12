//
// Created by profidoc on 11.04.2022.
//

#pragma once
#include "include/drawing/TileSet.h"
#include "SFML/System/Clock.hpp"

class Animator : public TileSet {
 public:
  Animator() = default;
  Animator(const Rect2u& sub_table);
  Animator(const Rect2u& sub_table, float frames_per_second);
  void Update(float delta_time);
  void SetFramesPerSecond(float frames_per_second);
  void SetState(uint32_t state_sub_coordinate_y);

 private:
  void NextFrame();
  uint32_t cur_frame_ = 0;
  float milliseconds_per_frame_ = 0;
  float frames_per_second_ = 0;
  float elapsed_time_ = 0;
};
