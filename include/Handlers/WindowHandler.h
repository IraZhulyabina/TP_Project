//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include "SFML/Graphics.hpp"
#include "include/BasicStructs/structs.h"
#include "string"

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