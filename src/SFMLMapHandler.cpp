#pragma once
#include "include/SFMLMapHandler.h"
#include <iostream>

void SFMLMapHandler::BuildMapDrawer(sf::RenderWindow* window,
                                    TextureManager& texture_manager,
                                    PhysicsEngine& physics_engine) {
  std::ifstream file(kMapSetsFilename);
  std::string line;
  if (file.is_open()) {
    while (getline(file, line)) {
      AddMapDrawer(line, window, texture_manager, physics_engine);
    }
  }
}

void SFMLMapHandler::DrawMap() {
  for (auto& drawer : drawers_) {
    drawer.Draw();
  }
}
void SFMLMapHandler::AddMapDrawer(std::string& layer_info,
                                  sf::RenderWindow* window,
                                  TextureManager& texture_manager,
                                  PhysicsEngine& physics_engine) {
  size_t right_position = layer_info.rfind(',');
  size_t left_position = layer_info.find(',');
  MapDrawer drawer;
  drawer.SetWindow(window);
  std::string CSVName = layer_info.substr(0, left_position);
  std::string MapFilename = layer_info.substr(left_position + 1, right_position - left_position - 1);
  int32_t map_tile_set_shape = std::stoi(layer_info.substr(right_position + 1));
  drawer.SetMapTiles(CSVName, kMapTileShape, map_tile_set_shape, physics_engine);
  drawer.SetTexture(texture_manager.GetTexture(MapFilename));
  drawers_.push_back(drawer);
}
