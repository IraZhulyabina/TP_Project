//
// Created by profidoc on 04.05.22.
//

#pragma once
#include "SFML/Graphics.hpp"

template <typename T>
class Vector2: public sf::Vector2<T> {
 private:
  using BaseVector = sf::Vector2<T>;

 public:
  using BaseVector::BaseVector;
  Vector2(const BaseVector& other) : BaseVector(other) {}

  template <typename U>
  explicit operator Vector2<U>() {
    return Vector2<U>(static_cast<U>(BaseVector::x),
                    static_cast<U>(BaseVector::y));
  }
};

using Vector2f = Vector2<float>;
using Vector2u = Vector2<uint32_t>;
using Vector2i = Vector2<int32_t>;