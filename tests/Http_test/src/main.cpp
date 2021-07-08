#include <gtest/gtest.h>

#include <Charger/Http/Server/libevent/Listener.hpp>
#include <Handlers/Handler.hpp>

int main(int argc, char** argv)
{
  Charger::Http::Server::libevent::Listener server("localhost", 8000);
  server.addHandler("/", std::make_shared<Charger::Http::TestHandlers::Handler>());
  server.serve();

  testing::InitGoogleTest(&argc, argv);
  auto code = RUN_ALL_TESTS();
  server.stop();
  return code;
}
