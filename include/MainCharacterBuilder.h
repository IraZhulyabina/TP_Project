//
// Created by profidoc on 06.05.22.
//

#pragma once
#include "MainCharacter.h"
#include "SFML/Graphics.hpp"
#include "TextureManager.h"

class MainCharacterBuilder {
 public:
  static MainCharacter Build(sf::RenderWindow& window,
                             TextureManager& texture_manager);

 private:
  inline static const std::string kMainCharacterFilename =
      "resources/textures/characters_stay.png";
  inline static const sf::Vector2i kPlayerTileShape = {48, 72};
  inline static const Vector2f kPLayerInitialPosition = {30, 30};
  static const size_t kPlayerTilesetRawLength = 3;
  static const uint64_t kPlayerFPS = 3;
};
