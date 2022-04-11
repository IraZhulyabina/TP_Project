//
// Created by profidoc on 08.04.2022.
//

#pragma once
#include "include/BasicStructs/structs.h"

class TileSet {  // интерфейс к текстурпаку, вырезающий нужный кусок
 public:
  TileSet() = default;
  explicit TileSet(const Rect2u& sub_table);
  const Coord2u& GetSubTableCoords() const;
  //  TODO: iterator for Shapes

 private:
  Rect2u sub_table_ = {0, 0, 0, 0};
  Coord2u cur_rect_coords_ = {0, 0};  // TODO: make an iterator, not a field
};


