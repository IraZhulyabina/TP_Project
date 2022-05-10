//
// Created by profidoc on 04.05.22.
//

#pragma once
#include "PhysicalEntity.h"
#include "SFMLDrawable.h"
#include "TableAnimated.h"

class MainCharacterBuilder;

class MainCharacter : public SFMLDrawable,
                      public PhysicalEntity,
                      public TableAnimated {
 public:
  MainCharacter& operator=(const MainCharacter&) = default;
  enum class PlayerStates {
    Stay = 0,
    Left = 2,
    Down = 1,
    Right = 3,
    Up = 4,
  };
  void SetPosition(const Vector2f& position) override;
  void Move(const Vector2f& shift) override;
  void SetState(PlayerStates state);
  void UpdateAnimation(uint64_t elapsed_time) override;

 private:
  friend class MainCharacterBuilder;
};