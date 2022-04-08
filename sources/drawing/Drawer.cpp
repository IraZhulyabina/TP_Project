//
// Created by profidoc on 20.03.2022.
//

#include "include/drawing/Drawer.h"
#include "include/drawing/TexturePack.h"
#include "include/drawing/TileSet.h"

void Drawer::Init() {  // TODO: catching an exception from constructor
  for (const std::string& filename: TexturePackResources::filenames) {
    if (texture_packs_.find(filename) == texture_packs_.end()) {
      texture_packs_[filename] = TexturePack(filename);
    }
  }
}

void Drawer::AddTarget(Drawable* target) {
  auto type = target->GetTileSetName();
  auto& texture_filename = TexturePackResources::filenames_map.at(type);
  TileSet tile_set(TexturePackResources::sub_tables_map.at(type));
  target->InitDrawable(&texture_packs_[texture_filename], tile_set);
  targets_.push_back(target);
}

void Drawer::DrawEntities(sf::RenderWindow& window) {
  for (Drawable* target : targets_) {
    window.draw(target->GetSprite());
  }
}

void Drawer::UpdateTargets() {
  for (Drawable* target : targets_) {
    target->Update();
  }
}
