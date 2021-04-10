#ifndef CHARGER_HTTPSERVER_RESPONSE_HPP
#define CHARGER_HTTPSERVER_RESPONSE_HPP

#include <string>

namespace Charger {
namespace HttpServer {

struct Response
{
public:
  int         code;
  std::string body;

};

} // namespace HttpServer
} // namespace Charger

#endif // CHARGER_HTTPSERVER_RESPONSE_HPP
