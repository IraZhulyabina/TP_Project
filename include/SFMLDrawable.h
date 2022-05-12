//
// Created by profidoc on 04.05.22.
//

#pragma once
#include <memory>

#include "SFML/Graphics.hpp"
#include "include/BasicDrawable.h"

class SFMLDrawable: BasicDrawable {
 public:
  void SetWindow(sf::RenderWindow* window);
  void Draw() override;
  void SetTexture(std::shared_ptr<sf::Texture> texture);

 protected:
  void SetDrawablePosition(const Vector2f& position) override;
  void MoveDrawable(const Vector2f& shift) override;
  void SetTextureRect(const Rect2i& rect) override;
  sf::RenderWindow* window_;
  sf::Sprite sprite_;
  std::shared_ptr<sf::Texture> texture_;
};
