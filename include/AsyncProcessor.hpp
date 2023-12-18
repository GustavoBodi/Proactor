#pragma once
#include <cstdint>
#include "IProactor.hpp"
#include "CompletionHandler.hpp"
#include "Handle.hpp"

class AsyncProcessor {
public:
  AsyncProcessor();
  void open(CompletionHandler *completion_handler, Handle handle, IProactor *proactor);
  void async_read(void *buffer, uint32_t size);
  void async_write(const void *buffer, uint32_t size);
private:
  CompletionHandler *completion_handler;
  IProactor *proactor;
  Handle handle;
};
