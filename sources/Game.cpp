//
// Created by profidoc on 20.03.2022.
//

#include "include/Game.h"
bool Game::Init() {
  window_handler_.InitWindow({800, 800}, "Game");
  // TODO make loadable settings of window
  window_handler_.GetWindow().setVerticalSyncEnabled(true);
  drawer_.Init();  // TODO: catch exceptions
  object_handler_.InitTargets(drawer_);
  return true;
}

Game::Game() { is_running_ = true;
}

bool Game::IsRunning() const {
  return is_running_;
}

bool Game::HandleEvents() {
  is_running_ = is_running_ && event_handler_.WindowEvents(window_handler_);
  return is_running_;
}

bool Game::IsWindowOpened() {
  return window_handler_.IsOpen();
}

void Game::UpdateGraphics() {
  drawer_.UpdateTargets();
}

void Game::Draw() {
  window_handler_.GetWindow().clear();  // TODO Make API
  drawer_.DrawEntities(window_handler_.GetWindow());
  window_handler_.GetWindow().display();  // TODO make API
}
