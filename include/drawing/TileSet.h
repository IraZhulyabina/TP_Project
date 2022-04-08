//
// Created by profidoc on 08.04.2022.
//

#pragma once
#include "include/main.h"

class TileSet {  // интерфейс к текстурпаку, вырезающий нужный кусок
 public:
  explicit TileSet(const Rect2u& sub_table);
  const Coord2u& GetSubTableCoords() const;
  //  TODO: iterator for Shapes

 private:
  Rect2u sub_table_;
  Coord2u cur_rect_coords_ = {0, 0};  // TODO: make an iterator, not a field
};


