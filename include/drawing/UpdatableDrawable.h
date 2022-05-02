//
// Created by ubuntu on 4/26/22.
//

#pragma once
#include "include/drawing/BasicDrawable.h"

class UpdatableDrawable : public BasicDrawable {
 public:
  virtual void Update(float frame_time) = 0;
};