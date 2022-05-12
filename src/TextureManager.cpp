//
// Created by profidoc on 04.05.22.
//

#include "TextureManager.h"
std::shared_ptr<sf::Texture> TextureManager::GetTexture(const std::string&
                                                         filename) {
  if (textures_.find(filename) == textures_.end()) {
    AddNewTexture(filename);
  }
  return textures_.at(filename);
}

void TextureManager::AddNewTexture(const std::string& filename) {
  auto new_texture = std::make_shared<sf::Texture>();
  new_texture->loadFromFile(filename);
  textures_[filename] = new_texture;
}
