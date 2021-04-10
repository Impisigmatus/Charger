#ifndef CHARGER_HTTPSERVER_RESPONSE_HPP
#define CHARGER_HTTPSERVER_RESPONSE_HPP

#include <string>

namespace Charger {
namespace HttpServer {

class Response
{
public:
  Response(const int&         code,
           const std::string& description,
           const std::string& body);

  std::string toString() const;

  int getCode() const;

private:
  int         mCode;
  std::string mDescription;
  std::string mBody;

};

} // namespace HttpServer
} // namespace Charger

#endif // CHARGER_HTTPSERVER_RESPONSE_HPP
