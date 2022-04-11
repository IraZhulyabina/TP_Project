#include "include/Game.h"

int main() {
  Game game;
  game.Init();

  while (game.IsWindowOpened() && game.IsRunning()) {
    if(!game.HandleEvents()) continue;
    game.UpdateGraphics();
    game.Draw();
  }

  return 0;
}
