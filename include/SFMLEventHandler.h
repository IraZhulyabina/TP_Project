#pragma once
#include "include/ObjectHandler.h"
#include "SFML/Graphics.hpp"
#include "BasicEventHandler.h"

class SFMLEventHandler : public BasicEventHandler<sf::RenderWindow> {
 public:
  void SetWindow(sf::RenderWindow* window) override;
  bool HandleWindowEvents() override;
  void HandleKeyBoardKeys(ObjectHandler& object_handler) override;
 private:
  sf::RenderWindow* window_;
};