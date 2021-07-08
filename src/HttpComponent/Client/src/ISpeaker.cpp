#include <ISpeaker.hpp>

namespace Charger::Http::Client {

Response ISpeaker::post(const Request& request) const
{
  return custom(request, "POST");
}

Response ISpeaker::put(const Request& request) const
{
  return custom(request, "PUT");
}

Response ISpeaker::get(const Request& request) const
{
  return custom(request, "GET");
}

Response ISpeaker::remove(const Request& request) const
{
  return custom(request, "DELETE");
}

} // namespace Charger::Http::Client
