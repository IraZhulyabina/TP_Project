//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include <vector>
#include "map"
#include "include/drawing/Drawable.h"
#include "include/drawing/TileSet.h"
#include "include/drawing/TexturePack.h"
#include "resources/headers/TexturePacksResources.h"
#include <string>

class Drawer {
 public:
  void Init();
  void AddTarget(Drawable* target);
  void DrawEntities(sf::RenderWindow& window);
  void UpdateTargets();

 private:
  std::map<std::string, TexturePack*> texture_packs_;
  std::vector<Drawable*> targets_;
};

