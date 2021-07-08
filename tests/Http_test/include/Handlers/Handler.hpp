#ifndef CHARGER_HTTP_TESTS_HANDLER_HPP
#define CHARGER_HTTP_TESTS_HANDLER_HPP

#include <Charger/Http/Server/AbstractHandler.hpp>

namespace Charger::Http::TestHandlers {

class Handler : public Server::AbstractHandler
{
public:
  Response post(const Server::Context& ctx) const override;
  Response put(const Server::Context& ctx) const override;
  Response get(const Server::Context& ctx) const override;

};

} // namespace Charger::Http::TestHandlers

#endif // CHARGER_HTTP_TESTS_HANDLER_HPP
