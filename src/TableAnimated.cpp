//
// Created by profidoc on 04.05.22.
//

#include "TableAnimated.h"

void TableAnimated::SetState(int32_t state) {
  cur_sub_table_coords_.y = state;
}

void TableAnimated::NextFrame() {
  cur_sub_table_coords_.x += 1;
  cur_sub_table_coords_.x %= frames_num_;
  cur_sub_table_coords_.x += anchor_coords_.x;
}

void TableAnimated::SetTileShape(const Vector2i& tile_shape) {
  tile_shape_ = tile_shape;
}

void TableAnimated::SetFramesNum(int32_t frames_num) {
  frames_num_ = frames_num;
}

Rect2i TableAnimated::GetRect() {
  return Rect2i(tile_shape_.x * cur_sub_table_coords_.x,
                cur_sub_table_coords_.y * tile_shape_.y,
                tile_shape_.x, tile_shape_.y) + anchor_coords_;
}

void TableAnimated::SetAnchorCoords(const Vector2i& anchor_coords) {
  anchor_coords_ = anchor_coords;
}
