//
// Created by profidoc on 04.05.22.
//

#include "Game.h"

#include <cmath>
void Game::Init() {
  std::srand(std::time(0));
  window_handler_.InitWindow(Vector2i(928, 928));
  physics_engine_.AddWalls(Vector2i(928, 928));
  map_handler_.BuildMapDrawer(&window_handler_.GetWindow(), texture_manager_, physics_engine_);
  object_handler_.Init(window_handler_.GetWindow(), texture_manager_, physics_engine_.GetSolids());
  event_handler_.SetWindow(&window_handler_.GetWindow());
  is_running_ = true;
}

bool Game::HandleEvents() {
  is_running_ &= event_handler_.HandleWindowEvents();
  event_handler_.HandleKeyBoardKeys(object_handler_);
  return is_running_;
}

bool Game::IsRunning() const { return is_running_; }

bool Game::IsWindowOpened() const { return window_handler_.IsWindowOpened(); }

void Game::Draw() {
  map_handler_.DrawMap();
  object_handler_.DrawTargets();
}

void Game::FrameEnd() { window_handler_.WindowDisplay(); }

void Game::FrameStart() {
  window_handler_.WindowClear();
  frame_time_ = main_clock_.getElapsedTime().asMicroseconds();
  main_clock_.restart();
}

std::optional<bool> Game::UpdatePhysics() {
  return physics_engine_.UpdatePhysics(frame_time_, object_handler_);
}

void Game::UpdateGraphics() {
  object_handler_.UpdateGraphics(frame_time_);
}