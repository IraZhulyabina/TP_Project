//
// Created by profidoc on 20.03.2022.
//

#include "include/Handlers/ObjectHandler.h"

void ObjectHandler::InitTargets(Drawer& drawer) {
  drawer.AddTarget(&main_character_);
}

const MainCharacter& ObjectHandler::GetMainCharacter() const {
  return main_character_;
}
