//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include "include/MapHandling/MapLoader.h"
#include "include/drawing/MapDrawer.h"
#include "resources/maps/FirstMap.h"
#include "include/drawing/Drawer.h"

class MapHandler {
 public:
  void Init();  // create tile-handlers, register in drawer
  void AddToDrawer(Drawer& drawer);

 private:
  MapLoader map_loader_;
  std::vector<std::vector<std::pair<Coord2u, ssize_t>>> layers_vectors_;
  std::vector<MapDrawer> drawers_;
};
