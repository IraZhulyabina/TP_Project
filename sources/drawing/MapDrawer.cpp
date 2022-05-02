//
// Created by ubuntu on 4/26/22.
//
#include "include/drawing/MapDrawer.h"

std::vector<std::pair<Coord2u, ssize_t>>* MapDrawer::GetObjectVector() {
  return objects_pointer_;
}
void MapDrawer::SetObjectVector(
    std::vector<std::pair<Coord2u, ssize_t>>* pointer) {
  objects_pointer_ = pointer;
}

void MapDrawer::Draw(sf::RenderWindow& window) {
  for (const auto& [pos, type] : *objects_pointer_) {
    map_rect_controller_.SetTileId(type);
    BasicDrawable::UpdateSpriteTexture();
    BasicDrawable::SetSpritePosition(
        Coord2f(pos.x * GetTileShape().x, pos.y * GetTileShape().y));
    window.draw(BasicDrawable::GetSprite());
  }
}

TileRectController& MapDrawer::GetRectController() {
  return map_rect_controller_;
}
void MapDrawer::SetTextureType(TexturePackResources::TileSetNames type) {
  BasicDrawable::tile_set_name_ = type;
}
