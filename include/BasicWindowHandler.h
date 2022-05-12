#pragma once
#include "include/structs/Vector2.h"


template<typename WindowType>
class BasicWindowHandler {
 public:
  virtual WindowType& GetWindow() = 0;
  virtual bool IsWindowOpened() const = 0;
  virtual void WindowDisplay() = 0;
  virtual void WindowClear() = 0;
  virtual void InitWindow(Vector2i shape) = 0;
};