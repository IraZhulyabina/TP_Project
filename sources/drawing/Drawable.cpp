//
// Created by profidoc on 23.03.2022.
//

#include "include/drawing/Drawable.h"

sf::Sprite &Drawable::GetSprite() {
  return sprite_;
}

TexturePackResources::TileSetNames Drawable::GetTileSetName() const {
  return tile_set_name_;
}

const Coord2f& Drawable::GetSpritePosition() {
  return sprite_.getPosition();
}

void Drawable::SetTileSet(TileSet& tile_set) {
  tile_set_ = tile_set;
}

void Drawable::InitDrawable(TexturePack *texture_pack, TileSet tile_set) {
  SetTileSet(tile_set);
  SetTexturePack(texture_pack);
  ApplyTexture();
  UpdateSpriteTexture();
}

void Drawable::SetTexturePack(TexturePack *texture_pack) {
  texture_pack_ = texture_pack;
}

void Drawable::UpdateSpriteTexture() {
  auto real_rect = texture_pack_->GetReact(tile_set_.GetSubTableCoords());
  sprite_.setTextureRect(real_rect);
}

void Drawable::ApplyTexture() {
  sprite_.setTexture(*texture_pack_->GetTexture());
}

void Drawable::SetSpritePosition(Coord2f pos) {
  sprite_.setPosition(pos);
}

