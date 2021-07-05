#include <gtest/gtest.h>

#include <Charger/Http/Client/Domain/Request.hpp>

#include <Charger/Http/Client/curl/Speaker.hpp>

TEST(Request, Set)
{
  std::map<std::string, std::string> args = {
    { "get_arg_1", "value 1" },
    { "get_arg_2", "value_2" },
    { "get_arg_3", "value_3" }
  };
  std::map<std::string, std::string> headers = {
    { "header_1", "value_1" },
    { "header_2", "value_2" },
    { "header_3", "value_3" }
  };

  Charger::Http::Client::Request request;
  request.set(Charger::Http::Client::Arg::URL       = "localhost",
              Charger::Http::Client::Arg::HEADERS   = headers);
  request.set(Charger::Http::Client::Arg::GET_ARGS  = args);

  EXPECT_EQ(request.getURL(), "localhost");
  EXPECT_EQ(request.getData(), std::string());
  EXPECT_EQ(request.getHeaders(), headers);
  EXPECT_EQ(request.getArgs(), args);
}

// TODO Сделать комплексный тест для клиент-сервера
