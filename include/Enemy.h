#pragma once
#include "PhysicalEntity.h"
#include "SFMLDrawable.h"
#include "TableAnimated.h"
#include "random"

class EnemyBuilder;

class Enemy : public SFMLDrawable,
              public PhysicalEntity,
              public TableAnimated {
 public:
  Enemy& operator=(const Enemy&) = default;
  enum class EnemyStates {
    Down = 6,
    Left = 7,
    Right = 8,
    Up = 9,
  };
  void SetPosition(const Vector2f& position) override;
  void Move(const Vector2f& shift) override;
  void SetState(EnemyStates state);
  void UpdateAnimation(uint64_t elapsed_time) override;
 private:
  friend class EnemyBuilder;
};
