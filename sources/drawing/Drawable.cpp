//
// Created by profidoc on 23.03.2022.
//

#include "include/drawing/Drawable.h"

sf::Sprite& Drawable::GetSprite() { return sprite_; }

TexturePackResources::TileSetNames Drawable::GetTileSetName() const {
  return tile_set_name_;
}

const Coord2f& Drawable::GetSpritePosition() { return sprite_.getPosition(); }

void Drawable::SetAnimator(Animator& tile_set) { animator_ = tile_set; }

void Drawable::InitDrawable(TexturePack* texture_pack, Animator animator) {
  SetAnimator(animator);
  SetTexturePack(texture_pack);
  ApplyTexture();
  UpdateSpriteTexture();
}

void Drawable::SetTexturePack(TexturePack* texture_pack) {
  texture_pack_ = texture_pack;
}

void Drawable::UpdateSpriteTexture() {
  auto real_rect = texture_pack_->GetReact(animator_.GetSubTableCoords());
  sprite_.setTextureRect(real_rect);
}

void Drawable::ApplyTexture() {
  sprite_.setTexture(*texture_pack_->GetTexture());
}

void Drawable::SetSpritePosition(Coord2f pos) { sprite_.setPosition(pos); }
bool Drawable::IsAnimated() const { return is_animated_; }

void Drawable::UpdateAnimator(float frame_time) {
  animator_.Update(frame_time);
}
