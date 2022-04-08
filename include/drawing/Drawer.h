//
// Created by profidoc on 20.03.2022.
//

#ifndef TP_SOURCES_DRAWER_H_
#include <vector>
#include "map"
#include "Drawable.h"
#include "include/drawing/TileSet.h"
#include "include/drawing/TexturePack.h"
#include "resources/headers/TexturePacksResources.h"
#include "string"
#define TP_SOURCES_DRAWER_H_

class Drawer {
 public:
  void Init();
  void AddTarget(Drawable* target);
  void DrawEntities(sf::RenderWindow& window);
  void UpdateTargets();

 private:
  std::map<std::string, TexturePack> texture_packs_;
  std::vector<Drawable*> targets_;
};

#endif //TP_SOURCES_DRAWER_H_
