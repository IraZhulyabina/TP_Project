#pragma once
#include "SFMLDrawable.h"
#include "CSVMapLoader.h"
#include "PhysicsEngine.h"

class MapDrawer : public SFMLDrawable {
 public:
  void Draw();
  void SetMapTiles(const std::string& filename, int32_t map_tile_shape,
                   int32_t map_tile_set_shape, PhysicsEngine& physics_engine);
 private:
  CSVMapLoader map_loader_;
  std::vector<std::vector<ssize_t>> map_tiles_;
  int32_t map_tile_shape_;
  int32_t map_tile_set_shape_;
};