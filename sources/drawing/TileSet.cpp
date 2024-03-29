//
// Created by profidoc on 08.04.2022.
//

#include "include/drawing/TileSet.h"

TileSet::TileSet(const Rect2u& sub_table) {
  sub_table_ = sub_table;
  cur_rect_coords_ = {sub_table.left, sub_table.top};
}

const Coord2u& TileSet::GetSubTableCoords() const {
  return cur_rect_coords_;
}
