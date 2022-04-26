//
// Created by profidoc on 23.03.2022.
//

#pragma once
#include "include/BasicStructs/structs.h"
#include "include/drawing/TexturePack.h"
#include "include/drawing/TileSet.h"
#include "resources/headers/TexturePacksResources.h"
#include "Animator.h"

class Drawable {
 public:
  void InitDrawable(TexturePack* texture_pack, Animator animator);
  virtual void Draw(sf::RenderWindow&) = 0;
  virtual void DrawingUpdate(float frame_time) = 0;

  sf::Sprite& GetSprite();
  TexturePackResources::TileSetNames GetTileSetName() const;
  bool IsAnimated() const;

 protected:
  const Coord2f& GetSpritePosition();
  void SetSpritePosition(Coord2f pos);
  void SetState(uint32_t state_sub_coordinate_y);

  TexturePackResources::TileSetNames tile_set_name_ =
      TexturePackResources::TileSetNames::Nothing;
  bool is_animated_ = false;
  void UpdateAnimator(float frame_time);
  void UpdateSpriteTexture(); // TODO: update using time and state

 private:
  void ApplyTexture();
  void SetAnimator(Animator& tile_set);
  void SetTexturePack(TexturePack* texture_pack);

  Animator animator_;
  TexturePack* texture_pack_ = nullptr;
  sf::Sprite sprite_;
};
