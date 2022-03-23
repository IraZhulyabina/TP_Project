#include <iostream>
#include "../include/Game.h"
#include <SFML/Graphics.hpp>
#include "../include/main.h"

int main() {
  Game game;
  game.Init();

  while (game.IsWindowOpened() && game.IsRunning()) {
    if(!game.HandleEvents()) continue;

  }

  return 0;
}
