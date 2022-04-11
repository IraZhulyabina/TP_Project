//
// Created by profidoc on 11.04.2022.
//

#include "include/drawing/Animator.h"

Animator::Animator(const Rect2u& sub_table, float frames_per_second)
    : TileSet(sub_table), frames_per_second_(frames_per_second) {}

void Animator::UpdateFrame(float delta_time) {
  elapsed_time_ += delta_time;
  cur_rect_coords_.x = // TODO:
}
