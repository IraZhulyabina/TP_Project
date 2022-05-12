#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "SFML/Graphics.hpp"
#include "include/MapDrawer.h"
#include "PhysicsEngine.h"
#include "TextureManager.h"
#include "BasicMapHandler.h"

class SFMLMapHandler : BasicMapHandler<sf::RenderWindow>{
 public:
  void BuildMapDrawer(sf::RenderWindow* window, TextureManager& texture_manager,
                      PhysicsEngine& physics_engine) override;
  void DrawMap() override;
 private:
  void AddMapDrawer(std::string& layer_info, sf::RenderWindow* window,
                    TextureManager& texture_manager, PhysicsEngine& physics_engine);
  std::vector<MapDrawer> drawers_;
  const std::string kMapSetsFilename = "resources/maps/map1/maps.txt";
  const int32_t kMapTileShape = 32;
};
