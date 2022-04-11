//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include "Entity.h"
#include "include/drawing/Drawable.h"
#include "include/Physics/PhysicalEntity.h"
#include "resources/headers/Kinematics.h"

class MainCharacter: public PhysicalEntity, public Drawable {
 public:
  MainCharacter();
  void SetRotation(float angle);
  void SetPosition(const Coord2f& position) override;
  void SetSpeed(float speed);
  virtual void Move(const Coord2f& delta) override;

 private:
  void DrawingUpdate() override;
  kinematics::Orientation orientation_ = kinematics::Orientation::Left;
};
