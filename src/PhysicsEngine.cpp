#pragma once
#include "PhysicsEngine.h"

std::optional<bool> PhysicsEngine::UpdatePhysics(uint64_t elapsed_time,
                                  ObjectHandler& object_handler) {
  UpdateMainCharacterPhysics(elapsed_time, object_handler);
  UpdateEnemyPhysics(elapsed_time, object_handler);
  for (auto tile : winning_exit_) {
    if (tile.intersects(object_handler.GetMainCharacter().GetPhysicalRect())) {
      return true;
    }
  }
  for (auto enemy : object_handler.GetEnemies()) {
    if (enemy.GetPhysicalRect().intersects(
            object_handler.GetMainCharacter().GetPhysicalRect())) {
      return false;
    }
  }
  return {};
}

void PhysicsEngine::AddSolidStructures(
    const std::vector<std::vector<ssize_t>>& solid_tiles, int32_t tile_shape) {
  for (size_t y = 0; y < solid_tiles.size(); ++y) {
    for (size_t x = 0; x < solid_tiles[y].size(); ++x) {
      if (solid_tiles[y][x] == -1) {
        continue;
      }
      solids_.emplace_back(Rect2f(static_cast<float>(x * tile_shape),
                                 static_cast<float>(y * tile_shape),
                                 tile_shape, tile_shape));
    }
  }
}
void PhysicsEngine::AddWalls(const Vector2i& shape) {
  for (size_t x = 0; x < shape.x; ++x) {
    solids_.emplace_back(x, 0, 1, 1);
    solids_.emplace_back(x, shape.y, 1, 1);
  }
  for (size_t y = 0; y < shape.y; ++y) {
    solids_.emplace_back(0, y, 1, 1);
    solids_.emplace_back(shape.x, y, 1, 1);
  }
}
void PhysicsEngine::UpdateEnemyPhysics(uint64_t elapsed_time,
                                       ObjectHandler& object_handler) {
  for (auto& enemy : object_handler.GetEnemies()) {
    float result_speed = enemy.GetSpeed() * static_cast<float>(elapsed_time) / kMicroSecondsToSeconds;
    if (std::rand() % 80 == 0) {
      uint32_t number_state = std::rand() % 4 + 1;
      Vector2f direction;
      switch (number_state) {
        case 1:
          enemy.SetState(Enemy::EnemyStates::Down);
          direction.x = 0;
          direction.y = 1;
          break;
        case 2:
          enemy.SetState(Enemy::EnemyStates::Left);
          direction.x = -1;
          direction.y = 0;
          break;
        case 3:
          enemy.SetState(Enemy::EnemyStates::Right);
          direction.x = 1;
          direction.y = 0;
          break;
        case 4:
          enemy.SetState(Enemy::EnemyStates::Up);
          direction.x = 0;
          direction.y = -1;
          break;
      }
      enemy.SetVelocityDirection(direction);
    }
    Vector2f shift = enemy.GetVelocityDirection() * result_speed;
    Rect2f supposed_rect = enemy.GetPhysicalRect();
    supposed_rect += shift;
    bool does_intersect = false;
    for (auto solid : solids_) {
      if (supposed_rect.intersects(solid)) {
        does_intersect = true;
        break;
      }
    }
    if (!does_intersect) {
      enemy.Move(shift);
    }
  }
}
void PhysicsEngine::UpdateMainCharacterPhysics(uint64_t elapsed_time,
                                               ObjectHandler& object_handler) {
  float result_speed = object_handler.GetMainCharacter().GetSpeed() *
                       static_cast<float>(elapsed_time) / kMicroSecondsToSeconds;
  Vector2f shift = object_handler.GetMainCharacter().GetVelocityDirection() * result_speed;
  Rect2f supposed_rect = object_handler.GetMainCharacter().GetPhysicalRect();
  supposed_rect += shift;
  bool does_intersect = false;
  for (auto solid : solids_) {
    if (supposed_rect.intersects(solid)) {
      does_intersect = true;
      break;
    }
  }
  if (!does_intersect) {
    object_handler.GetMainCharacter().Move(shift);
  }
}
std::vector<Rect2f>* PhysicsEngine::GetSolids() { return &solids_; }

void PhysicsEngine::AddWinningExit(const std::vector<std::vector<ssize_t>>& winning_tiles,
                                   int32_t tile_shape) {
  for (size_t y = 0; y < winning_tiles.size(); ++y) {
    for (size_t x = 0; x < winning_tiles[y].size(); ++x) {
      if (winning_tiles[y][x] == -1) {
        continue;
      }
      winning_exit_.emplace_back(Rect2f(static_cast<float>(x * tile_shape),
                                  static_cast<float>(y * tile_shape), tile_shape,
                                  tile_shape));
    }
  }
}
