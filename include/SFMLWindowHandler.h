#pragma once
#include "include/BasicWindowHandler.h"
#include "SFML/Graphics.hpp"

class SFMLWindowHandler : public BasicWindowHandler<sf::RenderWindow> {
 public:
  sf::RenderWindow& GetWindow() override;
  bool IsWindowOpened() const override;
  void WindowDisplay() override;
  void WindowClear() override;
  void InitWindow(Vector2i shape) override;
 private:
  sf::RenderWindow window_;
};