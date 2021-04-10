#ifndef CHARGER_HTTPSERVER_RESPONSE_HPP
#define CHARGER_HTTPSERVER_RESPONSE_HPP

#include <string>

namespace Charger {
namespace HttpServer {

struct Response
{
public:
  std::string toString() const;

  int         code;
  std::string description;
  std::string body;

};

} // namespace HttpServer
} // namespace Charger

#endif // CHARGER_HTTPSERVER_RESPONSE_HPP
