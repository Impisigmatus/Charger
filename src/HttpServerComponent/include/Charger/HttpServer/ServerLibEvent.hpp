#ifndef HTTPSERVER_SERVER_LIBEVENT_HPP
#define HTTPSERVER_SERVER_LIBEVENT_HPP

#include <Charger/HttpServer/IServer.hpp>

#include <evhttp.h>

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

};

} // namespace HttpServer

#endif // HTTPSERVER_SERVER_LIBEVENT_HPP
