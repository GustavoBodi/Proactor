#pragma once
#include <cstdint>

/*
 * @brief An alais to the internal error type
 */
using error_t = uint32_t;

/*
 * @brief An alais to the internal status type
 */
using status_t = bool;

class AsyncResult {
public:
  /*!
   * @brief The constructor of the async result type
   */
  AsyncResult() = default;

  /*!
   * @brief The destructor of the async result (trivial)
   */
  virtual ~AsyncResult() = default;

  /*!
   * @brief The completion handler
   */
  virtual void complete() = 0;

  /*!
   * @brief Get bytes to transfer
   */
  uint32_t get_size() const { return _size; }

  /*!
   * @brief Set bytes to transfer
   */
  void set_size(uint32_t size) { _size = size; }

  /*!
   * @brief Gets the status of the operation
   */
  status_t get_status() { return _status; }

  /*!
   * @brief Set the status of the operation
   */
  void set_status(status_t status) { _status = status; }

  /*!
   * @brief Returns the error if there is a failure
   */
  error_t get_error() { return _error; }

  /*!
   * @brief Sets the error for a certain failure
   */
  void set_error(error_t error) { _error = error; }
private:
  uint32_t _size;
  error_t _error;
  status_t _status;
};

