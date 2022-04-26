//
// Created by profidoc on 20.03.2022.
//

#include "include/drawing/Drawer.h"

void Drawer::Init() {  // TODO: catching an exception from constructor
  for (const std::string& filename: TexturePackResources::filenames) {
    if (texture_packs_.find(filename) == texture_packs_.end()) {
      texture_packs_[filename] = new TexturePack(filename);
    }
  }
}

void Drawer::AddTarget(BasicDrawable* target) {
  auto type = target->GetTileSetName();
  const auto& texture_filename = TexturePackResources::filenames_map.at(type);
  target->SetTexturePack(texture_packs_[texture_filename]);
  targets_.push_back(target);
}

void Drawer::DrawEntities(sf::RenderWindow& window) {
  for (BasicDrawable* target : targets_) {
    target->Draw(window);
  }
}

void Drawer::UpdateTargets(float frame_time) {
  for (UpdatableDrawable* target : updatable_targets_) {
    target->Update(frame_time);
  }
}

void Drawer::AddAnimatedTarget(AnimatedDrawable* target) {
  auto type = target->GetTileSetName();
  target->InitAnimator(TexturePackResources::sub_tables_map.at(type),
                       TexturePackResources::kNormalFramesPerSecond);
  // TODO: create a map for fps
  updatable_targets_.push_back(target);
}
