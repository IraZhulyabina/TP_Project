#include "include/Game.h"

int main() {
  Game game;
  game.Init();

  while (game.IsWindowOpened() && game.IsRunning()) {
    game.FrameStart();

    if (!game.HandleEvents()) {
      continue;
    }

    std::optional<bool> update_result = game.UpdatePhysics();
    if (update_result.has_value()) {
      if (update_result.value()) {
        std::cout << "Congrats! You won!!!";
        break;
      } else {
        std::cout << "You lost :(";
        break;
      }
    }
    game.UpdateGraphics();
    game.Draw();
    game.FrameEnd();
  }

  return 0;
}
