//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include "Handlers/EventHandler.h"
#include "Handlers/MapHandler.h"
#include "Handlers/ObjectHandler.h"
#include "Handlers/WindowHandler.h"
#include "include/drawing/Drawer.h"

class Game {
 public:
  Game();

  bool Init();
  bool HandleEvents();
  //  void UpdatePhysics();
  void UpdateGraphics();
  void Draw();
  //  bool EndGame();

  bool IsRunning() const;
  bool IsWindowOpened();

 private:
  MapHandler map_handler_;
  EventHandler event_handler_;
  ObjectHandler object_handler_;
  Drawer drawer_;
  WindowHandler window_handler_;

  bool is_running_ = false;
};
