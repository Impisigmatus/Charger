#ifndef CHARGER_HTTPSERVER_SERVER_LIBEVENT_HPP
#define CHARGER_HTTPSERVER_SERVER_LIBEVENT_HPP

#include <Charger/HttpServer/IServer.hpp>

#include <evhttp.h>

namespace Charger {
namespace HttpServer {

class ServerLibEvent : public IServer
{
public:
  ServerLibEvent(const std::string& host, const size_t port);

  bool serve() const override;
  void addHandler(const std::string& path,
                  const std::shared_ptr<IHandler>& handler) const override;

protected:
  static void reply(struct evhttp_request* request, Response response);

private:
  std::unique_ptr<event_base, decltype(&event_base_free)> mListener;
  std::unique_ptr<evhttp,     decltype(&evhttp_free)>     mServer;

private:
  static std::map<std::string, std::shared_ptr<IHandler>> mHandlers;

  static std::string M_NOT_FOUND;
  static std::string M_BAD_METHOD;

};

} // namespace HttpServer
} // namespace Charger

#endif // HTTPSERVER_SERVER_LIBEVENT_HPP
