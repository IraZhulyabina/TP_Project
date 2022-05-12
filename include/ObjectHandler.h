//
// Created by profidoc on 07.05.22.
//

#pragma once
#include "MainCharacter.h"
#include "MainCharacterBuilder.h"
#include "unordered_map"
#include "Enemy.h"
#include "EnemyBuilder.h"

class ObjectHandler {
 public:
  void Init(sf::RenderWindow& window, TextureManager& texture_manager,
            std::vector<Rect2f>* solids);

  MainCharacter& GetMainCharacter();
  std::vector<Enemy>& GetEnemies();

  float GetPlayerBasicSpeed() const;

  void DrawTargets();
  void UpdateGraphics(uint64_t elapsed_time);

 private:
  void InitMainCharacter(sf::RenderWindow& window, TextureManager& texture_manager);
  void InitEnemies(sf::RenderWindow& window, TextureManager& texture_manager,
                   std::vector<Rect2f>* solids);
  MainCharacter main_character_;
  std::vector<Enemy> enemies_;
  float player_basic_speed_ = kInitialPlayerBasicSpeed;
  const float enemy_speed_ = 100.0;
  static const float kInitialPlayerBasicSpeed;
  const uint32_t kNumberOfEnemies = 80;
};