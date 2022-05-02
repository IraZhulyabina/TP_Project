 //
// Created by ubuntu on 4/26/22.
//

#pragma once
#include "include/drawing/BasicDrawable.h"
#include "include/drawing/MapRectController.h"
#include "resources/headers/TexturePacksResources.h"
#include "resources/maps/FirstMap.h"
#include <iostream>

class MapDrawer : public BasicDrawable {
 public:
  MapDrawer() = default;
  void SetTextureType(TexturePackResources::TileSetNames type);
  std::vector<std::pair<Coord2u, ssize_t>>* GetObjectVector();
  void SetObjectVector(std::vector<std::pair<Coord2u, ssize_t>>* pointer);
  void Draw(sf::RenderWindow& window) override;
  TileRectController& GetRectController() override;

 protected:
  MapRectController map_rect_controller_;
  std::vector<std::pair<Coord2u, ssize_t>>* objects_pointer_;
};