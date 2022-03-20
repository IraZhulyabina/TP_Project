//
// Created by profidoc on 20.03.2022.
//

#include "../../include/Handlers/WindowHandler.h"

sf::RenderWindow & WindowHandler::GetWindow() const {
  return *window_;
}

Coord2u WindowHandler::GetShape() const {
  return window_->getSize();
}
WindowHandler::WindowHandler(sf::RenderWindow &window): window_(&window) {}
