#pragma once
#include "include/SFMLWindowHandler.h"

sf::RenderWindow& SFMLWindowHandler::GetWindow() {
  return window_;
}

bool SFMLWindowHandler::IsWindowOpened() const { return window_.isOpen(); }

void SFMLWindowHandler::WindowDisplay() { window_.display(); }

void SFMLWindowHandler::WindowClear() { window_.clear(); }

void SFMLWindowHandler::InitWindow(Vector2i shape) {
  window_.create(sf::VideoMode(shape.x, shape.y), "SuperGameV2");
}
