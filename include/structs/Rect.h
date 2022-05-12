//
// Created by profidoc on 04.05.22.
//

#pragma once
#include "SFML/Graphics.hpp"

template <typename T>
class Rect2: public sf::Rect<T> {
 private:
  using BaseRect = sf::Rect<T>;

 public:
  using BaseRect::BaseRect;
  Rect2(const BaseRect& rectangle) : BaseRect(rectangle) {}

  template <typename U>
  explicit operator Rect2<U>() {
    return Rect2<U>(static_cast<U>(BaseRect::left),
                    static_cast<U>(BaseRect::top),
                    static_cast<U>(BaseRect::width),
                    static_cast<U>(BaseRect::height));
  }

  Rect2& operator+=(const sf::Vector2<T>& delta) {
    BaseRect::left += delta.x;
    BaseRect::top += delta.y;
    return *this;
  }
};

template <typename T>
Rect2<T> operator+(Rect2<T> left, const sf::Vector2<T>& right) {
   return left += right;
}

template <typename T>
Rect2<T> operator-(Rect2<T> left, const sf::Vector2<T>& right) {
  return left -= right;
}

using Rect2f = Rect2<float>;
using Rect2u = Rect2<uint32_t>;
using Rect2i = Rect2<int32_t>;