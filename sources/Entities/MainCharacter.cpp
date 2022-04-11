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
  // TODO: make a setter, when PhysicalEntity implemented
}

void MainCharacter::SetRotation(float angle) {
  velocity_direction_ = UnitVector(angle);
  orientation_ = kinematics::AngleToOrientation(angle);
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
  PhysicalEntity::speed_ = speed;  // TODO: make API
}
