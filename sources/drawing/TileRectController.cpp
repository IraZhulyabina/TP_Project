//
// Created by profidoc on 08.04.2022.
//

#include "include/drawing/TileRectController.h"

TileRectController::TileRectController(const Rect2u& sub_table) {
  sub_table_ = sub_table;
  cur_rect_coords_ = {sub_table.left, sub_table.top};
}

const Coord2u& TileRectController::GetSubTableCoords() const {
  return cur_rect_coords_;
}
void TileRectController::SetSubTableCoords(const Coord2u& coords) {
  cur_rect_coords_ = coords;
}
