//
// Created by profidoc on 23.03.2022.
//

#pragma once
#include "include/BasicStructs/structs.h"
#include "include/drawing/TexturePack.h"
#include "include/drawing/TileRectController.h"
#include "resources/headers/TexturePacksResources.h"
#include "Animator.h"

class BasicDrawable {
 public:
  virtual void Draw(sf::RenderWindow&) = 0;

  TexturePackResources::TileSetNames GetTileSetName() const;
  void SetTexturePack(TexturePack* texture_pack);

 protected:
  sf::Sprite& GetSprite();
  const Coord2f& GetSpritePosition();
  void SetSpritePosition(Coord2f pos);
  //void SetState(uint32_t state_sub_coordinate_y);
  virtual TileRectController& GetRectController() = 0;

  TexturePackResources::TileSetNames tile_set_name_ =
      TexturePackResources::TileSetNames::Nothing;
  void UpdateSpriteTexture();

 private:
  void ApplyTexture();

  TexturePack* texture_pack_ = nullptr;
  sf::Sprite sprite_;
};
