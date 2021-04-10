#ifndef CHARGER_HTTPSERVER_ISERVER_HPP
#define CHARGER_HTTPSERVER_ISERVER_HPP

#include <Charger/HttpServer/IHandler.hpp>

#include <memory>

namespace Charger {
namespace HttpServer {

class IServer
{
public:
  IServer() = default;

  virtual bool serve() const = 0;

  virtual void addHandler(const std::string& path,
                          const std::shared_ptr<IHandler>& handler) const = 0;

};

} // namespace HttpServer
} // namespace Charger

#endif // CHARGER_HTTPSERVER_ISERVER_HPP
