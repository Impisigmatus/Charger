#include <AbstractHandler.hpp>

namespace Charger::Http::Server {

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

} // namespace Charger::Http::Server
