//
// Created by profidoc on 20.03.2022.
//

#include "include/Handlers/ObjectHandler.h"

void ObjectHandler::InitTargets(Drawer& drawer, PhysicsEngine& physics_engine) {
  drawer.AddTarget(&main_character_);
  drawer.AddAnimatedTarget(&main_character_);
  physics_engine.AddTarget(&main_character_);
}

MainCharacter& ObjectHandler::GetMainCharacter() {
  return main_character_;
}
