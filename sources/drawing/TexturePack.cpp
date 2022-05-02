//
// Created by profidoc on 08.04.2022.
//

#include "include/drawing/TexturePack.h"
Rect2i TexturePack::GetReact(Coord2u table_rect) const {
  return {tile_shape_.x * static_cast<int>(table_rect.x),
          tile_shape_.y * static_cast<int>(table_rect.y),
          tile_shape_.x, tile_shape_.y};
}

TexturePack::TexturePack(const std::string &filename) {
  filename_ = filename;
  table_shape_ = TexturePackResources::tables_map.at(filename);

  sf::Image image;
  image.loadFromFile(filename); // TODO: throw an exception if failing to load

  tile_shape_ = static_cast<Coord2i>(image.getSize());
  tile_shape_.x /= static_cast<int32_t>(table_shape_.x);
  tile_shape_.y /= static_cast<int32_t>(table_shape_.y);

  texture_ = new sf::Texture();
  texture_->loadFromImage(image);
}

sf::Texture *TexturePack::GetTexture() const { return texture_; }

TexturePack::~TexturePack() { delete texture_; }
const Coord2i& TexturePack::GetTileShape() const { return tile_shape_; }
