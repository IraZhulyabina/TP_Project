#include "include/CSVMapLoader.h"

std::vector<std::vector<ssize_t>> CSVMapLoader::LoadMap(const std::string& path) {
  std::vector<std::vector<ssize_t>> parsed_map;
  std::string line;
  std::ifstream file(path);
  if (file.is_open()) {
    while (getline(file, line)) {
      parsed_map.push_back(std::vector<ssize_t>());
      size_t position = 0;
      while ((position = line.find(',')) != std::string::npos) {
        std::string number = line.substr(0, position);
        parsed_map.back().push_back(static_cast<ssize_t>(std::stoll(number)));
        line.erase(0, position + 1);
      }
      parsed_map.back().push_back(static_cast<ssize_t>(std::stoll(line)));
    }
  }
  return parsed_map;
}
