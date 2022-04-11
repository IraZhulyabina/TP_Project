//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include "include/Entities/MainCharacter.h"
#include "include/drawing/Drawer.h"
#include "include/Physics/PhysicsEngine.h"

class ObjectHandler {
 public:
  void InitTargets(Drawer& drawer, PhysicsEngine& physics_engine);
  MainCharacter& GetMainCharacter();

 private:
  MainCharacter main_character_;  // TODO: use Creator
};
