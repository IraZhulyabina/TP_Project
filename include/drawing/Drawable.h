//
// Created by profidoc on 23.03.2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "include/main.h"
#include "include/drawing/TexturePack.h"
#include "include/drawing/TileSet.h"
#include "resources/headers/TexturePacksResources.h"

class Drawable {
 public:
  sf::Sprite& GetSprite();
  const Coord2f& GetPosition();
  void SetPosition(Coord2f pos);

  TexturePackResources::TileSetNames GetTileSetName() const;
  void InitDrawable(TexturePack* texture_pack, TileSet tile_set);
  virtual void Update() = 0;

 private:
  void ApplyTexture();
  void UpdateSpriteTexture(); // TODO: update using time and state

  void SetTileSet(TileSet& tile_set);
  void SetTexturePack(TexturePack* texture_pack);

  TexturePackResources::TileSetNames tile_set_name_;
  TileSet tile_set_;
  TexturePack* texture_pack_ = nullptr;
  sf::Sprite sprite_;
  // Coord2f position_;
};
