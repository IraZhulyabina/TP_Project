#pragma once
#include "ObjectHandler.h"
#include <optional>

class PhysicsEngine {
 public:
  std::optional<bool> UpdatePhysics(uint64_t elapsed_time, ObjectHandler& object_handler);
  void AddSolidStructures(const std::vector<std::vector<ssize_t>>& solid_tiles,
                          int32_t tile_shape);
  void AddWinningExit(const std::vector<std::vector<ssize_t>>& solid_tiles,
                      int32_t tile_shape);
  void AddWalls(const Vector2i& shape);
  std::vector<Rect2f>* GetSolids();
 private:
  void UpdateMainCharacterPhysics(uint64_t elapsed_time, ObjectHandler& object_handler);
  void UpdateEnemyPhysics(uint64_t elapsed_time, ObjectHandler& object_handler);
  std::vector<Rect2f> solids_;
  std::vector<Rect2f> winning_exit_;

  const int32_t kMicroSecondsToSeconds = 1'000'000;
};