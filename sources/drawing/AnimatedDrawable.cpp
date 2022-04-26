//
// Created by ubuntu on 4/26/22.
//
#include "include/drawing/AnimatedDrawable.h"

void AnimatedDrawable::Update(float frame_time) {
  animator_.Update(frame_time);
}

void AnimatedDrawable::InitAnimator(const Rect2u& sub_table, float fps) {
  animator_ = Animator(sub_table, fps);
}

void AnimatedDrawable::SetState(uint32_t state_sub_coordinate_y) {
  animator_.SetState(state_sub_coordinate_y);
}
