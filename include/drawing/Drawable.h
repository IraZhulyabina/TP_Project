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
  sf::Sprite& GetSprite();
  virtual void DrawingUpdate() = 0;
  virtual void Draw(sf::RenderWindow&) = 0;
  TexturePackResources::TileSetNames GetTileSetName() const;
  void InitDrawable(TexturePack* texture_pack, Animator animator);
  bool IsAnimated() const;

 protected:
  const Coord2f& GetSpritePosition();
  void SetSpritePosition(Coord2f pos);

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
