#include "MapDrawer.h"
#include <iostream>

void MapDrawer::Draw() {
  for (size_t y = 0; y < map_tiles_.size(); ++y) {
    for (size_t x = 0; x < map_tiles_[y].size(); ++x) {
      if (map_tiles_[y][x] == -1) {
        continue;
      }
      auto type = static_cast<int32_t>(map_tiles_[y][x]);
      sf::Rect<int32_t> cur_rect((type % map_tile_set_shape_) * map_tile_shape_,
                                 (type / map_tile_set_shape_) * map_tile_shape_,
                                 map_tile_shape_, map_tile_shape_);
      sprite_.setTextureRect(cur_rect);
      sprite_.setPosition(static_cast<float>(x * map_tile_shape_),
                                     static_cast<float>(y * map_tile_shape_));
      window_->draw(sprite_);
    }
  }
}

void MapDrawer::SetMapTiles(const std::string& filename, int32_t map_tile_shape,
                            int32_t map_tile_set_shape, PhysicsEngine& physics_engine) {
  map_tiles_ = map_loader_.LoadMap(filename.substr(filename.find(':') + 1));
  if (filename.substr(0, filename.find(':')) == "1") {
    physics_engine.AddSolidStructures(map_tiles_, map_tile_shape);
  }
  if (filename.substr(0, filename.find(':')) == "2") {
    physics_engine.AddWinningExit(map_tiles_, map_tile_shape);
  }
  map_tile_shape_ = map_tile_shape;
  map_tile_set_shape_ = map_tile_set_shape;
}
