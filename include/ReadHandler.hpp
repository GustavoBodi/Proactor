#pragma once
#include "AsyncProcessor.hpp"
#include "CompletionHandler.hpp"
#include "IProactor.hpp"

class ReadHandler: CompletionHandler {
public:
  ReadHandler( IProactor *proactor ): CompletionHandler(proactor) {}

  void handle_event(Handle handle, AsyncResult &result);
  Handle get_handle() const;
  void read();

private:
  AsyncProcessor async_processor;
  Handle handle;
};
