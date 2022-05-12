#include "Enemy.h"
void Enemy::SetPosition(const Vector2f& position) {
  PhysicalEntity::SetPhysicalPosition(position);
  SFMLDrawable::SetDrawablePosition(position);
}

void Enemy::Move(const Vector2f& shift) {
  PhysicalEntity::MovePhysical(shift);
  SFMLDrawable::MoveDrawable(shift);
}

void Enemy::SetState(Enemy::EnemyStates state) {
  TableAnimated::SetState(static_cast<int32_t>(state));
}
void Enemy::UpdateAnimation(uint64_t elapsed_time) {
  TableAnimated::UpdateRect(elapsed_time);
  SFMLDrawable::SetTextureRect(TableAnimated::GetRect());
}