#pragma once
#include "TextureManager.h"
#include "PhysicsEngine.h"


template<typename WindowType>
class BasicMapHandler {
 public:
  virtual void BuildMapDrawer(WindowType* window, TextureManager& texture_manager,
                              PhysicsEngine& physics_engine) = 0;
  virtual void DrawMap() = 0;
};