//
// Created by profidoc on 11.04.2022.
//

#include "include/drawing/Animator.h"

Animator::Animator(const Rect2u& sub_table, float frames_per_second)
    : TileSet(sub_table), frames_per_second_(frames_per_second) {
  milliseconds_per_frame_ =
      kinematics::kMilliSecondsInSecond / frames_per_second_;
}

void Animator::Update(float delta_time) {
  elapsed_time_ += delta_time;
  if (elapsed_time_ >= milliseconds_per_frame_) {
    NextFrame();
    elapsed_time_ = FloatModule(elapsed_time_, milliseconds_per_frame_);
  }
}

void Animator::SetFramesPerSecond(float frames_per_second) {
  frames_per_second_ = frames_per_second;
  milliseconds_per_frame_ =
      kinematics::kMilliSecondsInSecond / frames_per_second_;
}

void Animator::NextFrame() {
  cur_frame_ += 1;
  cur_frame_ %= TileSet::sub_table_.width;
  TileSet::cur_rect_coords_.x = TileSet::sub_table_.left + cur_frame_;
}

void Animator::SetState(uint32_t state_sub_coordinate_y) {
  TileSet::cur_rect_coords_.y =
      TileSet::sub_table_.top + state_sub_coordinate_y;
}
Animator::Animator(const Rect2u& sub_table) : TileSet(sub_table) {}
