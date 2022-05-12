
#include "SFMLEventHandler.h"
#include <cmath>

void SFMLEventHandler::SetWindow(sf::RenderWindow* window) {
  window_ = window;
}
bool SFMLEventHandler::HandleWindowEvents() {
  sf::Event event;
  while (window_->pollEvent(event)) {
    switch (event.type) {
      case (sf::Event::Closed):
        window_->close();
        return false;

      case (sf::Event::KeyPressed):
        if (event.key.code == sf::Keyboard::Space) {
          break;
        }
        if (event.key.code == sf::Keyboard::Escape) {
          window_->close();
          return false;
        }

      default:
        continue;
    }
  }
  return true;
}
void SFMLEventHandler::HandleKeyBoardKeys(ObjectHandler& object_handler) {
  MainCharacter& m_ch = object_handler.GetMainCharacter();
  float player_basic_speed = object_handler.GetPlayerBasicSpeed();
  sf::Vector2f new_velocity = {0, 0};
  m_ch.SetSpeed(0);
  m_ch.SetState(MainCharacter::PlayerStates::Stay);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    m_ch.SetSpeed(player_basic_speed);
    new_velocity.y += 1;
    m_ch.SetState(MainCharacter::PlayerStates::Down);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    m_ch.SetSpeed(player_basic_speed);
    new_velocity.x -= 1;
    m_ch.SetState(MainCharacter::PlayerStates::Left);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    m_ch.SetSpeed(player_basic_speed);
    new_velocity.x += 1;
    m_ch.SetState(MainCharacter::PlayerStates::Right);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    m_ch.SetSpeed(player_basic_speed);
    new_velocity.y -= 1;
    m_ch.SetState(MainCharacter::PlayerStates::Up);
  }
  float len =
      std::sqrt(new_velocity.x * new_velocity.x + new_velocity.y * new_velocity.y);
  if (len != 0) {
    new_velocity /= len;
  }
  m_ch.SetVelocityDirection(new_velocity);
}
