#include "include/Game.h"

int main() {
  Game game;
  game.Init();

  while (game.IsWindowOpened() && game.IsRunning()) {
    game.FrameStart();

    if (!game.HandleEvents()) {
      continue;
    }

    game.UpdatePhysics();
    game.UpdateGraphics();
    game.Draw();
  }

  return 0;
}
