#pragma once
#include "Enemy.h"
#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include "MainCharacter.h"

class EnemyBuilder {
 public:
  static Enemy Build(sf::RenderWindow& window, TextureManager& texture_manager,
                     std::vector<Rect2f>* solids, MainCharacter& main_character);

 private:
  inline static const std::string kEnemyFilename =
      "resources/textures/characters_stay.png";
  inline static const sf::Vector2i kEnemyTileShape = {48, 72};
  static const size_t kEnemyTilesetRawLength = 3;
  static const uint64_t kEnemyFPS = 3;
  inline static const float kEnemySpeed = 100.0;
};