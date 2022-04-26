//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include <SFML/System/Clock.hpp>

#include "Handlers/EventHandler.h"
#include "Handlers/ObjectHandler.h"
#include "Handlers/WindowHandler.h"
#include "include/MapHandling/MapHandler.h"
#include "include/Physics/PhysicsEngine.h"
#include "include/drawing/Drawer.h"

class Game {
 public:
  Game();

  bool Init();
  void FrameStart();
  bool HandleEvents();
  void UpdatePhysics();
  void UpdateGraphics();
  void Draw();
//  void FrameEnd();
//  bool EndGame();

  bool IsRunning() const;
  bool IsWindowOpened();

 private:
  MapHandler map_handler_;
  EventHandler event_handler_;
  ObjectHandler object_handler_;
  PhysicsEngine physics_engine_;
  Drawer drawer_;
  WindowHandler window_handler_;
  sf::Clock main_clock_;
  float frame_time_ = 0;

  bool is_running_ = false;
};
