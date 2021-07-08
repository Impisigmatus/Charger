#include <Handlers/Handler.hpp>

namespace Charger::Http::TestHandlers {

Response Handler::post(const Server::Context& ctx) const
{
  return { 200, "OK", ctx.getBody() };
}

Response Handler::put(const Server::Context& ctx) const
{
  std::string data;
  for (const auto& header : ctx.getHeaders())
    data += header.first + ": " + header.second + "\n";
  return { 200, "OK", data };
}

Response Handler::get(const Server::Context& ctx) const
{
  std::string data;
  for (const auto& arg : ctx.getArgs())
    data += arg.first + ": " + arg.second + "\n";
  return { 200, "OK", data };
}

} // namespace Charger::Http::TestHandlers
