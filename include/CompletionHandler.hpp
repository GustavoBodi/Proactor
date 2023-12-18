#pragma once
#include "Proactor.hpp"
#include "AsyncResult.hpp"
#include "Handle.hpp"

/*!
 * @brief The abstract class that represents the processing of async operations
 */
class CompletionHandler {
public:
  CompletionHandler (Proactor *proactor): _proactor{proactor} {}
  virtual ~CompletionHandler() = default;

  virtual void handle_event(Handle handle, AsyncResult &result) = 0;
  virtual Handle get_handle() const = 0;

protected:
  Proactor *_proactor;
};

