//
// Created by profidoc on 04.05.22.
//

#include "SFMLDrawable.h"

void SFMLDrawable::SetWindow(sf::RenderWindow* window) { window_ = window; }

void SFMLDrawable::Draw() {
  if (window_ == nullptr) {
    throw std::invalid_argument("no window!");
  }
  window_->draw(sprite_);
}

void SFMLDrawable::SetDrawablePosition(const Vector2f& position) {
  sprite_.setPosition(position);
}

void SFMLDrawable::SetTexture(std::shared_ptr<sf::Texture> texture) {
  texture_ = texture;
  sprite_.setTexture(*texture);
}

void SFMLDrawable::SetTextureRect(const Rect2i& rect) {
  sprite_.setTextureRect(rect);
}

void SFMLDrawable::MoveDrawable(const Vector2f& shift) {
  sprite_.move(shift);
}
