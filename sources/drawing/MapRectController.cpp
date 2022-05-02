//
// Created by ubuntu on 4/26/22.
//
#include "include/drawing/MapRectController.h"

MapRectController::MapRectController(const Rect2u& sub_table)
    : TileRectController(sub_table), sub_table_(sub_table) {}

void MapRectController::SetTileId(uint32_t tile_id) {
  cur_tile_id_ = tile_id;
  UpdateSubTableCoords();
}
void MapRectController::UpdateSubTableCoords() {
  TileRectController::SetSubTableCoords(Coord2u(cur_tile_id_ % 16,
                                                cur_tile_id_ / 16));
  //TODO: make a constant
}
