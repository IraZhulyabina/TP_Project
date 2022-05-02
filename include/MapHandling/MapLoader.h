//
// Created by ubuntu on 4/27/22.
//

#pragma once
#include <string>
#include <fstream>
#include <vector>

class MapLoader{
 public:
  std::vector<std::vector<ssize_t>> LoadMap(const std::string& path);
};