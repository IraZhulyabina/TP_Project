//
// Created by profidoc on 20.03.2022.
//

#ifndef TP_SOURCES_HANDLERS_WINDOWHANDLER_H_
#include "SFML/Graphics.hpp"
#include "../main.h"
#include "string"
#define TP_SOURCES_HANDLERS_WINDOWHANDLER_H_

class WindowHandler {
 public:
  WindowHandler(sf::RenderWindow &window);
  sf::RenderWindow & GetWindow() const;
  Coord2u GetShape() const;

 private:
  sf::RenderWindow* window_;
};

#endif //TP_SOURCES_HANDLERS_WINDOWHANDLER_H_
