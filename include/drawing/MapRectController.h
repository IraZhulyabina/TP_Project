//
// Created by ubuntu on 4/26/22.
//

#pragma once
#include "include/drawing/TileRectController.h"

class MapRectController : public TileRectController {
 public:
  MapRectController() = default;
  MapRectController(const Rect2u& sub_table);
  void SetTileId(uint32_t tile_id);
 private:
  void UpdateSubTableCoords();
  uint32_t cur_tile_id_;
  Rect2u sub_table_;
};