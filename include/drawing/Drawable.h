//
// Created by profidoc on 23.03.2022.
//

#pragma once
#include "include/BasicStructs/structs.h"
#include "include/drawing/TexturePack.h"
#include "include/drawing/TileSet.h"
#include "resources/headers/TexturePacksResources.h"

class Drawable {
 public:
  sf::Sprite& GetSprite();
  virtual void DrawingUpdate() = 0;
  TexturePackResources::TileSetNames GetTileSetName() const;
  void InitDrawable(TexturePack* texture_pack, TileSet tile_set);

 protected:
  const Coord2f& GetSpritePosition();
  void SetSpritePosition(Coord2f pos);

  TexturePackResources::TileSetNames tile_set_name_ =
      TexturePackResources::TileSetNames::Nothing;

 private:
  void ApplyTexture();
  void UpdateSpriteTexture(); // TODO: update using time and state
  void SetTileSet(TileSet& tile_set);
  void SetTexturePack(TexturePack* texture_pack);

  TileSet tile_set_;
  TexturePack* texture_pack_ = nullptr;
  sf::Sprite sprite_;
  // Coord2f position_;
};
