#pragma once
#include "EnemyBuilder.h"
#include <iostream>


Enemy EnemyBuilder::Build(sf::RenderWindow& window, TextureManager& texture_manager,
                          std::vector<Rect2f>* solids, MainCharacter& main_character) {
  Enemy enemy;
  enemy.SetWindow(&window);
  auto texture = texture_manager.GetTexture(kEnemyFilename);
  enemy.SetTexture(texture);
  enemy.SetTileShape(kEnemyTileShape);
  enemy.SetPhysicalShape(kEnemyTileShape);
  enemy.SetAnchorCoords({0, 6});
  enemy.SetTextureRect(Rect2i(0, 6, kEnemyTileShape.x,
                              kEnemyTileShape.y));
  enemy.SetAnchorCoords(Vector2i(0, 6));
  bool is_intersecting;
  do {
    is_intersecting = false;
    Vector2f enemy_position = {static_cast<float>(std::rand() % 900),
                            static_cast<float>(std::rand() % 900)};
    enemy.SetPosition(enemy_position);
    for (auto& solid : *solids) {
      if (solid.intersects(enemy.GetPhysicalRect())) {
        is_intersecting = true;
        break;
      }
    }
    if (enemy_position.x < 100 || enemy_position.y < 100) {
      is_intersecting = true;
    }
  } while (is_intersecting);
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
  enemy.SetFramesNum(kEnemyTilesetRawLength);
  enemy.SetFramesPerSecond(kEnemyFPS);
  enemy.SetVelocityDirection(direction);
  enemy.SetSpeed(kEnemySpeed);
  return enemy;
}