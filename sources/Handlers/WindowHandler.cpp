//
// Created by profidoc on 20.03.2022.
//

#include "../../include/Handlers/WindowHandler.h"

sf::RenderWindow& WindowHandler::GetWindow() {
  return window_;
}

Coord2u WindowHandler::GetShape() const {
  return window_.getSize();
}

WindowHandler::WindowHandler() = default;

void WindowHandler::InitWindow(Coord2u shape, const std::string &title) {
  title_ = title;
  window_.create(sf::VideoMode(shape.x, shape.y), title);
}

const std::string &WindowHandler::GetTitle() const {
  return title_;
}

void WindowHandler::SetTitle(const std::string &title) {
  title_ = title;
  window_.setTitle(title_);
}

bool WindowHandler::IsOpen() {
  return window_.isOpen();
}

void WindowHandler::CloseWindow() {
  window_.close();
}
