//
// Created by profidoc on 08.04.2022.
//

#pragma once
#include "map"
#include "include/BasicStructs/structs.h"
#include "string"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "resources/headers/TexturePacksResources.h"

class TexturePack {  // носитель текстуры, то есть множества тайлсетов
 public:
  TexturePack() = default;
  explicit TexturePack(const std::string& filename);
  ~TexturePack();

  sf::Texture* GetTexture() const;
  const Coord2i& GetTileShape() const;

  Rect2i GetReact(Coord2u table_rect) const;

 private:
  std::string filename_;
  Coord2i tile_shape_;
  Coord2u table_shape_;
  sf::Texture* texture_ = nullptr;
};
