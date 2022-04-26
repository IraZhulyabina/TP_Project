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

void Drawer::AddTarget(Drawable* target) {
  auto type = target->GetTileSetName();
  const auto& texture_filename = TexturePackResources::filenames_map.at(type);
  Animator animator(TexturePackResources::sub_tables_map.at(type));
  if (target->IsAnimated()) {
    animator.SetFramesPerSecond(TexturePackResources::kNormalFramesPerSecond);
  }
  target->InitDrawable(texture_packs_[texture_filename], animator);
  targets_.push_back(target);
}

void Drawer::DrawEntities(sf::RenderWindow& window) {
  for (Drawable* target : targets_) {
    target->Draw(window);
  }
}

void Drawer::UpdateTargets(float frame_time) {
  for (Drawable* target : targets_) {
    if (target->IsAnimated()) {
      target->DrawingUpdate(frame_time);
    }
  }
}
