//
// Created by profidoc on 20.03.2022.
//

#ifndef TP_SOURCES_HANDLERS_WINDOWHANDLER_H_
#include "SFML/Graphics.hpp"
#include "include/BasicStructs/structs.h"
#include "string"
#define TP_SOURCES_HANDLERS_WINDOWHANDLER_H_

class WindowHandler {
 public:
  WindowHandler();

  sf::RenderWindow& GetWindow();
  Coord2u GetShape() const;
  void InitWindow(Coord2u shape, const std::string& title);
  const std::string &GetTitle() const;
  void SetTitle(const std::string &title);
  bool IsOpen();
  void CloseWindow();

 private:
  sf::RenderWindow window_;
  std::string title_;
};

#endif //TP_SOURCES_HANDLERS_WINDOWHANDLER_H_
