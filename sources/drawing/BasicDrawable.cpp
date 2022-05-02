//
// Created by profidoc on 23.03.2022.
//

#include "include/drawing/BasicDrawable.h"

sf::Sprite& BasicDrawable::GetSprite() { return sprite_; }

TexturePackResources::TileSetNames BasicDrawable::GetTileSetName() const {
  return tile_set_name_;
}

const Coord2f& BasicDrawable::GetSpritePosition() { return sprite_.getPosition(); }

void BasicDrawable::SetTexturePack(TexturePack* texture_pack) {
  texture_pack_ = texture_pack;
  ApplyTexture();
  UpdateSpriteTexture();
}

void BasicDrawable::UpdateSpriteTexture() {
  auto real_rect = texture_pack_->GetReact(GetRectController().
                                           GetSubTableCoords());
  sprite_.setTextureRect(real_rect);
}

void BasicDrawable::ApplyTexture() {
  sprite_.setTexture(*texture_pack_->GetTexture());
}

void BasicDrawable::SetSpritePosition(Coord2f pos) { sprite_.setPosition(pos); }
Coord2i BasicDrawable::GetTileShape() {
  return texture_pack_->GetTileShape();
}

/*void BasicDrawable::SetState(uint32_t state_sub_coordinate_y) {
  animator_.SetState(state_sub_coordinate_y);
}*/
