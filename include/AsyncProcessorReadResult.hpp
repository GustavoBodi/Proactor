#pragma once
#include "AsyncResult.hpp"
#include "CompletionHandler.hpp"

class AsyncProcessorReadResult: public AsyncResult {
public:
  AsyncProcessorReadResult(CompletionHandler *completion_handler): completion_handler{completion_handler} {}

  void complete();

private:
    CompletionHandler* completion_handler;
};

