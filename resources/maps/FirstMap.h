//
// Created by profidoc on 27.04.22.
//

#pragma once
#include <map>
#include <string>
#include "resources/headers/TexturePacksResources.h"

namespace TileMap1 {
  const std::string dir_path = "maps/map1/";
  const size_t layer_number = 2;
  const std::map<size_t, TexturePackResources::TileSetNames> types = {
      {0, TexturePackResources::TileSetNames::MapGrass},
      {1, TexturePackResources::TileSetNames::MapWalls}
  };
}