//
// Created by profidoc on 20.03.2022.
//

#include "../../include/Handlers/EventHandler.h"
bool EventHandler::WindowInteractions() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
    return false;
  }
  return true;
}
EventHandler::EventHandler(sf::RenderWindow& window) : window_(&window) {}
