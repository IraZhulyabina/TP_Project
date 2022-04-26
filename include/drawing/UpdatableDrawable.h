//
// Created by ubuntu on 4/26/22.
//

#pragma once
#include "include/drawing/BasicDrawable.h"

class UpdatableDrawable : BasicDrawable {
 public:
  virtual void UpdateDrawable(float frame_time) = 0;
};