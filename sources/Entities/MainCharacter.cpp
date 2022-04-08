//
// Created by profidoc on 20.03.2022.
//

#include "include/Entities/MainCharacter.h"

void MainCharacter::DrawingUpdate() {
  Drawable::SetSpritePosition(Entity::position_);
}

MainCharacter::MainCharacter() {
  Drawable::tile_set_name_ = TexturePackResources::Player;
  Entity::position_ = {10, 10};
  // TODO: make a setter, when Physics implemented
}
