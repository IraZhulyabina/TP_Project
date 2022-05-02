//
// Created by ubuntu on 4/26/22.
//

#pragma once
#include "include/drawing/UpdatableDrawable.h"
#include "include/drawing/Animator.h"

class AnimatedDrawable : public UpdatableDrawable {
 public:
  void InitAnimator(const Rect2u& sub_table, float fps);

 protected:
  void SetState(uint32_t state_sub_coordinate_y);
  Animator animator_;

 private:
  TileRectController& GetRectController() { return animator_; }
};