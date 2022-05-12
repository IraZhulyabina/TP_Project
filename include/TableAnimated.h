//
// Created by profidoc on 04.05.22.
//

#pragma once
#include "BasicAnimated.h"

class TableAnimated : public BasicAnimated {
 protected:
  void SetState(int32_t state);
  void SetTileShape(const Vector2i& tile_shape);
  void SetFramesNum(int32_t frames_num);
  Rect2i GetRect();
  void SetAnchorCoords(const Vector2i& anchor_coords);

 private:
  void NextFrame() override;
  Vector2i tile_shape_;
  Vector2i cur_sub_table_coords_;
  Vector2i anchor_coords_ = {0, 0};
  int32_t frames_num_ = 1;
};
