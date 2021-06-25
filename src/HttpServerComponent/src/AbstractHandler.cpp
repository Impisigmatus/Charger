#include <Charger/HttpServer/AbstractHandler.hpp>

namespace Charger {
namespace HttpServer {

const Response AbstractHandler::post(const Context&) const
{
  return { 405, "Method Not Allowed", "Method Not Allowed" };
}

const Response AbstractHandler::put(const Context&) const
{
  return { 405, "Method Not Allowed", "Method Not Allowed" };
}

const Response AbstractHandler::get(const Context&) const
{
  return { 405, "Method Not Allowed", "Method Not Allowed" };
}

const Response AbstractHandler::remove(const Context&) const
{
  return { 405, "Method Not Allowed", "Method Not Allowed" };
}

} // namespace HttpServer
} // namespace Charger
