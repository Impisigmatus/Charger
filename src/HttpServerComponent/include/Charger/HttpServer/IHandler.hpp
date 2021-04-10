#ifndef CHARGER_HTTPSERVER_IHANDLER_HPP
#define CHARGER_HTTPSERVER_IHANDLER_HPP

#include <Charger/HttpServer/Domain/Context.hpp>
#include <Charger/HttpServer/Domain/Response.hpp>

namespace Charger {
namespace HttpServer {

class IHandler
{
public:
  virtual Response post  (const Context& context) const = 0;
  virtual Response put   (const Context& context) const = 0;
  virtual Response get   (const Context& context) const = 0;
  virtual Response remove(const Context& context) const = 0;

};

} // namespace HttpServer
} // namespace Charger

#endif // CHARGER_HTTPSERVER_IHANDLER_HPP
