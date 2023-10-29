//
// Created by profidoc on 20.03.2022.
//

#include "include/Entities/MainCharacter.h"

void MainCharacter::DrawingUpdate(float frame_time) {
  Drawable::SetSpritePosition(Entity::position_);
  Drawable::UpdateAnimator(frame_time);
  Drawable::UpdateSpriteTexture();
}

MainCharacter::MainCharacter() {
  Drawable::tile_set_name_ = TexturePackResources::Player;
  Entity::position_ = {10, 10};  // TODO: move to ObjHandler
  Drawable::is_animated_ = true;
}

void MainCharacter::SetRotation(float angle) {
  orientation_ = kinematics::AngleToOrientation(angle);
  Drawable::SetState(TexturePackResources::moving_states.at(orientation_));
}

void MainCharacter::Move(const Coord2f& delta) {
  position_ += delta;
  PhysicalEntity::MovePhysical(delta);
}

void MainCharacter::SetPosition(const Coord2f& position) {
  position_ = position;
  PhysicalEntity::SetPhysicalPosition(position);
}

void MainCharacter::SetSpeed(float speed) {
  PhysicalEntity::speed_ = speed;
}

void MainCharacter::Draw(sf::RenderWindow& window) {
  window.draw(GetSprite());
}