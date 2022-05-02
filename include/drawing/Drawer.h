//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include <vector>
#include "map"
#include "include/drawing/BasicDrawable.h"
#include "include/drawing/TileRectController.h"
#include "include/drawing/TexturePack.h"
#include "include/drawing/UpdatableDrawable.h"
#include "include/drawing/AnimatedDrawable.h"
#include "resources/headers/TexturePacksResources.h"
#include <string>

class Drawer {
 public:
  void Init();
  void AddTarget(BasicDrawable* target, size_t layer = SIZE_MAX);
  void AddAnimatedTarget(AnimatedDrawable* target);
  void DrawEntities(sf::RenderWindow& window);
  void UpdateTargets(float frame_time);

 private:
  std::map<std::string, TexturePack*> texture_packs_;
  std::map<size_t, std::vector<BasicDrawable*>> targets_;
  std::vector<UpdatableDrawable*> updatable_targets_;
};

