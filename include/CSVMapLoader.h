#pragma once
#include <vector>
#include <string>
#include <fstream>


class CSVMapLoader {
 public:
  std::vector<std::vector<ssize_t>> LoadMap(const std::string& path);
};