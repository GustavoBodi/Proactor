#pragma once
#include <atomic>
#include <string>
#include <cstdint>
#include <memory>
#include <mutex>
#include "Proactor.hpp"

class TcpServer {
public:
  TcpServer(std::string ip, uint32_t port);
  ~TcpServer();

  void run();
  void stop();
  void is_running();

private:
  std::unique_ptr<Proactor> proactor;
  std::string ip_adderss;
  std::mutex mtx;
  std::atomic<bool> running;
  uint32_t port;
};
