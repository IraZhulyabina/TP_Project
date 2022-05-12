//
// Created by profidoc on 04.05.22.
//

#pragma once
#include <cstdint>
#include "structs/Rect.h"
#include "structs/Vector2.h"

class BasicAnimated {
 public:
  virtual void UpdateAnimation(uint64_t elapsed_time) = 0;

 protected:
  virtual void UpdateRect(uint64_t elapsed_time);
  virtual void NextFrame() = 0;
  void SetFramesPerSecond(uint64_t frames_per_second);

  uint64_t MicroSecondsPerFrame_;
  constexpr static const float kMicroSecondsPerSecond = 1'000'000;
  uint64_t elapsed_time_ = 0;
};