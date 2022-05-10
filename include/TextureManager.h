//
// Created by profidoc on 04.05.22.
//

#pragma once
#include "string"
#include "unordered_map"
#include "SFML/Graphics.hpp"
#include "memory"

class TextureManager {
 public:
  std::shared_ptr<sf::Texture> GetTexture(const std::string& filename);

 private:
  void AddNewTexture(const std::string& filename);
  std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures_;
};
