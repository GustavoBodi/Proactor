#pragma once 
#include "Handle.hpp"

class IProactor {
public:
  virtual void register_handle(Handle handle) = 0;
  virtual void handle_events() = 0;
};
