#include <gtest/gtest.h>

#include <Charger/Http/Client/Domain/Request.hpp>
#include <Charger/Http/Client/curl/Speaker.hpp>

TEST(Client, GetArgs)
{
  std::map<std::string, std::string> args = {
    { "get_arg_1", "value_1"},   // Слитно маленькими английскими буквами
    { "get_arg_2", "Значение 2"} // Раздельно, русскими буквами с заглавной
  };

  Charger::Http::Client::curl::Speaker client;
  Charger::Http::Client::Request request;
  Charger::Http::Response response = { 0, "" };

  { // Аргументы только в url
    request.set(Charger::Http::Client::Arg::URL = "localhost:8000?get_arg_0=value_0");
    response = client.get(request);

    EXPECT_EQ(response.getCode(), 200);
    EXPECT_EQ(response.getReason(), "OK");
    EXPECT_EQ(response.getBody(), "get_arg_0: value_0\n");
  }

  { // Аргументы только объектом
    request.set(Charger::Http::Client::Arg::URL = "localhost:8000",
                Charger::Http::Client::Arg::GET_ARGS = args);
    response = client.get(request);

    EXPECT_EQ(response.getCode(), 200);
    EXPECT_EQ(response.getReason(), "OK");
    EXPECT_EQ(response.getBody(), "get_arg_1: value_1\nget_arg_2: Значение 2\n");
  }

  { // Аргументы и в url и в объекте
    request.set(Charger::Http::Client::Arg::URL = "localhost:8000?get_arg_0=value_0");
    response = client.get(request);

    EXPECT_EQ(response.getCode(), 200);
    EXPECT_EQ(response.getReason(), "OK");
    EXPECT_EQ(response.getBody(), "get_arg_0: value_0\nget_arg_1: value_1\nget_arg_2: Значение 2\n");
  }
}

TEST(Client, Body)
{
  Charger::Http::Client::Request request;
  request.set(Charger::Http::Client::Arg::URL = "localhost:8000",
              Charger::Http::Client::Arg::DATA = "Hello World!");
  Charger::Http::Client::curl::Speaker client;
  auto response = client.post(request);

  EXPECT_EQ(response.getCode(), 200);
  EXPECT_EQ(response.getReason(), "OK");
  EXPECT_EQ(response.getBody(), "Hello World!");
}

TEST(Client, Headers)
{
  std::map<std::string, std::string> headers = {
    { "custom_header_1", "value_1"},   // Слитно маленькими английскими буквами
    { "custom_header_2", "Значение 2"} // Раздельно, русскими буквами с заглавной
  };

  Charger::Http::Client::curl::Speaker client;
  Charger::Http::Client::Request request;
  request.set(Charger::Http::Client::Arg::URL = "localhost:8000",
              Charger::Http::Client::Arg::HEADERS = headers);
  auto response = client.put(request);

  EXPECT_EQ(response.getCode(), 200);
  EXPECT_EQ(response.getReason(), "OK");
  EXPECT_EQ(response.getBody(), "Accept: */*\nContent-Length: 0\nContent-Type: application/x-www-form-urlencoded\nHost: localhost:8000\ncustom_header_1: value_1\ncustom_header_2: Значение 2\n");
}

TEST(Client, InvalidMethod)
{
  Charger::Http::Client::curl::Speaker client;
  Charger::Http::Client::Request request;
  request.set(Charger::Http::Client::Arg::URL = "localhost:8000");
  auto response = client.custom(request, "UNKNOWN");

  EXPECT_EQ(response.getCode(), 501);
  EXPECT_EQ(response.getReason(), "Not Implemented");
  EXPECT_EQ(response.getBody(), "<HTML><HEAD>\n<TITLE>501 Not Implemented</TITLE>\n</HEAD><BODY>\n<H1>Not Implemented</H1>\n</BODY></HTML>");
}

TEST(Client, InvalidURI)
{
  Charger::Http::Client::curl::Speaker client;
  Charger::Http::Client::Request request;
  Charger::Http::Response response = { 0, "" };

  { // Неверное имя хоста
    request.set(Charger::Http::Client::Arg::URL = "localhosta:8000");
    response = client.get(request);

    EXPECT_EQ(response.getCode(), 400);
    EXPECT_EQ(response.getReason(), "Bad Request");
    EXPECT_EQ(response.getBody(), "Couldn't resolve host name");
  }

  { // Неверный порт
    request.set(Charger::Http::Client::Arg::URL = "localhost:8001");
    response = client.get(request);

    EXPECT_EQ(response.getCode(), 400);
    EXPECT_EQ(response.getReason(), "Bad Request");
    EXPECT_EQ(response.getBody(), "Couldn't connect to server");
  }

  { // Неверный путь
    request.set(Charger::Http::Client::Arg::URL = "localhost:8000/path");
    response = client.get(request);

    EXPECT_EQ(response.getCode(), 404);
    EXPECT_EQ(response.getReason(), "Not Found");
    EXPECT_EQ(response.getBody(), "Not Found");
  }

  { // Случайный символ
    request.set(Charger::Http::Client::Arg::URL = "localhost:8000;");
    response = client.get(request);

    EXPECT_EQ(response.getCode(), 400);
    EXPECT_EQ(response.getReason(), "Bad Request");
    EXPECT_EQ(response.getBody(), "URL using bad/illegal format or missing URL");
  }
}
