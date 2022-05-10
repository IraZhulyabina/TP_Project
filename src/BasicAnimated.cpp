//
// Created by profidoc on 04.05.22.
//

#include "BasicAnimated.h"
void BasicAnimated::SetFramesPerSecond(uint64_t frames_per_second) {
  MicroSecondsPerFrame_ = kMicroSecondsPerSecond / frames_per_second;
}

void BasicAnimated::UpdateRect(uint64_t elapsed_time) {
  elapsed_time_ += elapsed_time;
  if (elapsed_time_ > MicroSecondsPerFrame_) {
    elapsed_time_ %= MicroSecondsPerFrame_;
    NextFrame();
  }
}
