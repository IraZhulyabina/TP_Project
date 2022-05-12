#pragma once
#include "include/ObjectHandler.h"


template<typename WindowType>
class BasicEventHandler {
 public:
  virtual void SetWindow(WindowType* window) = 0;
  virtual bool HandleWindowEvents() = 0;
  virtual void HandleKeyBoardKeys(ObjectHandler& object_handler) = 0;
 private:
  WindowType* window_;
};