//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include "include/Entities/MainCharacter.h"
#include "include/drawing/Drawer.h"

class ObjectHandler {
 public:
  void InitTargets(Drawer& drawer);
  const MainCharacter& GetMainCharacter() const;

 private:
  MainCharacter main_character_;  // TODO: use Creator
};
