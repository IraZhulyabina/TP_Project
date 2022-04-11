//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include "Entity.h"
#include "include/drawing/Drawable.h"

class MainCharacter: public Entity, public Drawable {
 public:
  MainCharacter();

 private:
  void DrawingUpdate() override;

};
