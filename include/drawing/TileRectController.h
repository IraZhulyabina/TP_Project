//
// Created by profidoc on 08.04.2022.
//

#pragma once
#include "include/BasicStructs/structs.h"

class TileRectController {  // интерфейс к текстурпаку, вырезающий нужный кусок
 public:
  TileRectController() = default;
  explicit TileRectController(const Rect2u& sub_table);
  const Coord2u& GetSubTableCoords() const;

 protected:
  void SetSubTableCoords(const Coord2u& coords);
  Rect2u sub_table_ = {0, 0, 1, 1};

 private:
  Coord2u cur_rect_coords_ = {0, 0};
};