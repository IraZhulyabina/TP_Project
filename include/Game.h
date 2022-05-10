//
// Created by profidoc on 04.05.22.
//

#pragma once
#include <cmath>

#include "MainCharacter.h"
#include "MainCharacterBuilder.h"
#include "ObjectHandler.h"
#include "SFMLWindowHandler.h"
#include "SFML/Graphics.hpp"
#include "SFMLDrawable.h"
#include "SFMLEventHandler.h"
#include "SFMLMapHandler.h"
#include "PhysicsEngine.h"
#include "TableAnimated.h"
#include "TextureManager.h"
#include "fstream"
#include "iostream"
#include "optional"
#include "string"
#include "random"

class Game {
 public:
  void Init();
  void FrameStart();
  bool HandleEvents();
  std::optional<bool> UpdatePhysics();
  void UpdateGraphics();
  void Draw();
  void FrameEnd();

  bool IsWindowOpened() const;
  bool IsRunning() const;

 private:
  TextureManager texture_manager_;
  ObjectHandler object_handler_;

  sf::Clock main_clock_;
  uint32_t frame_time_ = 0;
  bool is_running_ = false;

  SFMLWindowHandler window_handler_;
  SFMLEventHandler event_handler_;
  SFMLMapHandler map_handler_;
  PhysicsEngine physics_engine_;
};