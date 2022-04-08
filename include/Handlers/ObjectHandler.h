//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include "include/Entities/MainCharacter.h"
#include "include/drawing/Drawer.h"

class ObjectHandler {
 public:
  void InitTargets(Drawer& drawer);
  MainCharacter main_character;  // TODO: use Creator
};
