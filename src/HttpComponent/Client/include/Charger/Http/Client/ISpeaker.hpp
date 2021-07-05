#ifndef CHARGER_HTTP_CLIENT_ISPEAKER_HPP
#define CHARGER_HTTP_CLIENT_ISPEAKER_HPP

#include <Charger/Http/Response.hpp>
#include <Charger/Http/Client/Domain/Request.hpp>

namespace Charger::Http::Client {

class ISpeaker
{
public:
  Response post(const Request& request) const;
  Response put(const Request& request) const;
  Response get(const Request& request) const;
  Response remove(const Request& request) const;

  virtual Response custom(const Request& request, const::std::string& method) const = 0;

};

} // namespace Charger::Http::Client

#endif // CHARGER_HTTP_CLIENT_ISPEAKER_HPP
