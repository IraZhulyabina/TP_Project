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
  WindowHandler(Coord2u shape, std::string &title);
  const sf::RenderWindow &GetWindow() const;
  const Coord2u &GetShape() const;

 private:
  sf::RenderWindow window_;
  Coord2u shape_;
};

#endif //TP_SOURCES_HANDLERS_WINDOWHANDLER_H_
