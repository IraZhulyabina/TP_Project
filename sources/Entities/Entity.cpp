//
// Created by profidoc on 20.03.2022.
//

#include "include/Entities/Entity.h"

Entity::Entity(const Coord2f& position) { position_ = position; }

Coord2f& Entity::GetPosition() { return position_; }

void Entity::SetPosition(const Coord2f& position) { position_ = position; }

void Entity::Move(const Coord2f& delta) {}
