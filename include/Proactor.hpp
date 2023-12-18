#pragma once
#include "IProactor.hpp"
#include "Handle.hpp"

class Proactor: public IProactor {
public:
  void register_handle(Handle handle);
  void handle_events();
  static IProactor *instance();

private:
  static IProactor *proactor;
};
