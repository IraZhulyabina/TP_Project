//
// Created by profidoc on 20.03.2022.
//

#include "../include/Game.h"
bool Game::Init() {
  return false;
}
Game::Game(sf::RenderWindow& window_): window_handler_(window_) {
  is_running = true;
}
bool Game::IsRunning() const {
  return is_running;
}
bool Game::HandleEvents() {

  return false;
}
