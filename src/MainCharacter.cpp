//
// Created by profidoc on 04.05.22.
//

#include "MainCharacter.h"
void MainCharacter::SetPosition(const Vector2f& position) {
  PhysicalEntity::SetPhysicalPosition(position);
  SFMLDrawable::SetDrawablePosition(position);
}

void MainCharacter::Move(const Vector2f& shift) {
  PhysicalEntity::MovePhysical(shift);
  SFMLDrawable::MoveDrawable(shift);
}

void MainCharacter::SetState(MainCharacter::PlayerStates state) {
  TableAnimated::SetState(static_cast<int32_t>(state));
}
void MainCharacter::UpdateAnimation(uint64_t elapsed_time) {
  TableAnimated::UpdateRect(elapsed_time);
  SFMLDrawable::SetTextureRect(TableAnimated::GetRect());
}