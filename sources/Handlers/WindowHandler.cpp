//
// Created by profidoc on 20.03.2022.
//

#include "../../include/Handlers/WindowHandler.h"

const sf::RenderWindow &WindowHandler::GetWindow() const {
  return window_;
}

WindowHandler::WindowHandler(Coord2u shape, std::string &title):
    window_(sf::VideoMode(static_cast<size_t>(shape.x),
                          static_cast<size_t>(shape.y)), title),
    shape_(shape) {}

const Coord2u &WindowHandler::GetShape() const {
  return shape_;
}
