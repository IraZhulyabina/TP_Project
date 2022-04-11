//
// Created by profidoc on 20.03.2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

using Coord2f = sf::Vector2f;
using Coord2u = sf::Vector2u;
using Coord2i = sf::Vector2i;
using Rect2f = sf::Rect<float>;
using Rect2u = sf::Rect<uint32_t>;
using Rect2i = sf::Rect<int32_t>;

float Coord2fAbs(const Coord2f& vect);
float Rad(float angle);
Coord2f UnitVector(float angle);
float GetAngle(const Coord2f& vect);