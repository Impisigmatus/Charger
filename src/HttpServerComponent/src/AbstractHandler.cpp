#include <Charger/HttpServer/AbstractHandler.hpp>

namespace Charger {
namespace HttpServer {

Response AbstractHandler::post(const Context&) const
{
  return { 405, "Method Not Allowed" };
}

Response AbstractHandler::put(const Context&) const
{
  return { 405, "Method Not Allowed" };
}

Response AbstractHandler::get(const Context&) const
{
  return { 405, "Method Not Allowed" };
}

Response AbstractHandler::remove(const Context&) const
{
  return { 405, "Method Not Allowed" };
}

} // namespace HttpServer
} // namespace Charger
