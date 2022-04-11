//
// Created by profidoc on 20.03.2022.
//

#include "include/Entities/Entity.h"

Entity::Entity(const Coord2f& position) { position_ = position; }

Coord2f& Entity::GetPosition() { return position_; }