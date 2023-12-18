#include "CompletionHandler.hpp"
#include "Proactor.hpp"

class ReadHandler: CompletionHandler {
public:
  ReadHandler( Proactor *proactor ): CompletionHandler(proactor) {}

  void handle_event(Handle handle, AsyncResult &result);
  Handle get_handle() const;
  void read();

private:
  AsyncProcessor async_processor;
  Handle handle;
};
