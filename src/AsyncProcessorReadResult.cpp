#include "AsyncProcessorReadResult.hpp"

void AsyncProcessorReadResult::complete() {
  completion_handler->handle_event( completion_handler->get_handle(), *this );
}
