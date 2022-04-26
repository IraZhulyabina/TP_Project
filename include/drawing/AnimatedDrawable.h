//
// Created by ubuntu on 4/26/22.
//

#pragma once
#include "include/drawing/UpdatableDrawable.h"
#include "include/drawing/Animator.h"

class AnimatedDrawable : UpdatableDrawable {
 public:
  void Update(float frame_time);
  void InitAnimator(const Rect2u& sub_table, float fps);

 protected:
  void SetState(uint32_t state_sub_coordinate_y);

 private:
  TileRectController& GetRectController() { return animator_; }
  Animator animator_;
};