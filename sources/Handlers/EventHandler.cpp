//
// Created by profidoc on 20.03.2022.
//

#include "include/Handlers/EventHandler.h"

bool EventHandler::WindowEvents(WindowHandler& window_handler) {
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

bool EventHandler::PlayerInteract(ObjectHandler& object_handler) {
  object_handler.GetMainCharacter().SetSpeed(0);
  const float kNewPlayerSpeed = 200 * kinematics::kSecondsInMillisecond;
  // TODO: // make a const
  Coord2f velocity_dir = {0, 0};
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    velocity_dir.x += 1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    velocity_dir.y += 1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    velocity_dir.x += -1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    velocity_dir.y += -1;
  }
  object_handler.GetMainCharacter().SetRotation(GetAngle(velocity_dir));
  object_handler.GetMainCharacter().SetVelocity(velocity_dir);
  if (velocity_dir != Coord2f(0, 0)) {
    object_handler.GetMainCharacter().SetSpeed(kNewPlayerSpeed);
  }
  return true;
}
