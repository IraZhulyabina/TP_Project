//
// Created by profidoc on 20.03.2022.
//

#include "include/MapHandling/MapHandler.h"
void MapHandler::Init() {
  drawers_.resize(TileMap1::layer_number);
  layers_vectors_.resize(TileMap1::layer_number);
  for (size_t layer_index = 0; layer_index < TileMap1::layer_number;
       ++layer_index) {
    std::string cur_path = TileMap1::dir_path;
    cur_path += std::to_string(layer_index) + ".csv";
    uint32_t max_x_coord = 0;
    uint32_t max_y_coord = 0;
    std::vector<std::vector<ssize_t>> loaded = map_loader_.LoadMap(cur_path);
    for (uint32_t y = 0; y < loaded.size(); ++y) {
      for (uint32_t x = 0; x < loaded[y].size(); ++x) {
        if (loaded[y][x] == -1) {
          continue;
        }
        max_x_coord = std::max(max_x_coord, x);
        max_y_coord = std::max(max_y_coord, y);
        layers_vectors_[layer_index].push_back({{x, y}, loaded[y][x]});
      }
    }
    drawers_[layer_index].SetObjectVector(&layers_vectors_[layer_index]);
    drawers_[layer_index].SetTextureType(TileMap1::types.at(layer_index));
  }
}

void MapHandler::AddToDrawer(Drawer& drawer) {
  for (size_t layer_index = 0; layer_index < drawers_.size(); ++layer_index) {
    drawer.AddTarget(&drawers_[layer_index], layer_index);
  }
}
