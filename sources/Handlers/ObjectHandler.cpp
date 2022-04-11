//
// Created by profidoc on 20.03.2022.
//

#include "include/Handlers/ObjectHandler.h"

void ObjectHandler::InitTargets(Drawer& drawer) {
  Drawable& drawable_part = main_character;

  drawer.AddTarget(&drawable_part);
}
