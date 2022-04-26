 //
// Created by ubuntu on 4/26/22.
//

#pragma once
#include "include/drawing/BasicDrawable.h"

class MapDrawer : public BasicDrawable {
 public:
  std::vector<std::pair<Coord2u, uint32_t>>* GetObjectVector();
  void SetObjectVector(std::vector<std::pair<Coord2u, uint32_t>>* pointer);
 protected:
  std::vector<std::pair<Coord2u, uint32_t>>* objects_pointer_;
};