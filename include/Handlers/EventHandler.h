//
// Created by profidoc on 20.03.2022.
//

#ifndef TP_SOURCES_EVENTHANDLER_H_
#include "SFML/Graphics.hpp"
#include "WindowHandler.h"
#define TP_SOURCES_EVENTHANDLER_H_

class EventHandler {
 public:
  bool WindowEvents(WindowHandler &window_handler);  //TODO close window e.t.c.
  void PlayerInteract();  // TODO keyboard and mouse interaction
  void TimerInteraction();  // TODO events of timer

};

#endif //TP_SOURCES_EVENTHANDLER_H_
