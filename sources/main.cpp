#include <iostream>
#include "../include/Game.h"
#include <SFML/Graphics.hpp>
#include "../include/main.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

  Game game(window);

  while (window.isOpen() && game.IsRunning()) {
    if(!game.HandleEvents()) continue;
  }

  return 0;
}
