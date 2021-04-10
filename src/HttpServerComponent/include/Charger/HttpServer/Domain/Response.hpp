#ifndef HTTPSERVER_RESPONSE_HPP
#define HTTPSERVER_RESPONSE_HPP

#include <string>

namespace HttpServer {

struct Response
{
public:
  int         code;
  std::string body;

};

} // namespace HttpServer

#endif // HTTPSERVER_RESPONSE_HPP
