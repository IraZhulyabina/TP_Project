//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include "SFML/Graphics.hpp"
#include "WindowHandler.h"
#include "ObjectHandler.h"

class EventHandler {
 public:
  bool WindowEvents(WindowHandler &window_handler);  //TODO close window e.t.c.
  bool PlayerInteract(ObjectHandler& object_handler);
  // TODO keyboard and mouse interaction
  void TimerInteraction();  // TODO events of timer

};
