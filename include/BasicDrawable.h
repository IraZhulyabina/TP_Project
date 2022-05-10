//
// Created by profidoc on 04.05.22.
//

#pragma once
#include "include/structs/Vector2.h"
#include "include/structs/Rect.h"

class BasicDrawable {
 public:
  virtual void Draw() = 0;

 protected:
  virtual void SetDrawablePosition(const Vector2f& position) = 0;
  virtual void MoveDrawable(const Vector2f& shift) = 0;
  virtual void SetTextureRect(const Rect2i& rect) = 0;
};
