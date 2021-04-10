#ifndef CHARGER_HTTPSERVER_PARSER_LIBEVENT_HPP
#define CHARGER_HTTPSERVER_PARSER_LIBEVENT_HPP

#include <evhttp.h>

#include <map>
#include <vector>
#include <string>

namespace Charger {
namespace HttpServer {

class ParserLibevent
{
public:
  static std::string getBody(const struct evhttp_request* request);
  static std::vector<std::string> getPath(const struct evhttp_request* request);
  static std::map<std::string, std::string> getUriArgs(const struct evhttp_request* request);
  static std::map<std::string, std::string> getHeaders(const struct evhttp_request* request);

};

} // namespace HttpServer
} // namespace Charger

#endif // HTTPSERVER_PARSER_LIBEVENT_HPP
