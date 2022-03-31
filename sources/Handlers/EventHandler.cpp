//
// Created by profidoc on 20.03.2022.
//

#include "../../include/Handlers/EventHandler.h"

bool EventHandler::WindowEvents(WindowHandler &window_handler) {
  auto& window = window_handler.GetWindow();
  sf::Event event;
  while (window.pollEvent(event)) {
    switch (event.type) {
      case (sf::Event::Closed):
        window_handler.CloseWindow();
        return false;

      case (sf::Event::LostFocus):
        // TODO pause game on lost focus
        break;

      case (sf::Event::KeyPressed):
        if (event.key.code == sf::Keyboard::Space) {
          // TODO "jump" on space
          break;
        }
        if (event.key.code == sf::Keyboard::Escape) {
          window_handler.CloseWindow();
          return false;
        }

      default:
        continue;
    }
  }

  return true;
}