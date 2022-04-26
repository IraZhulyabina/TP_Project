//
// Created by ubuntu on 4/26/22.
//
#include "include/drawing/MapDrawer.h"

std::vector<std::pair<Coord2u, uint32_t>>* MapDrawer::GetObjectVector() {
  return objects_pointer_;
}
void MapDrawer::SetObjectVector(
    std::vector<std::pair<Coord2u, uint32_t>>* pointer) {
  objects_pointer_ = pointer;
}
