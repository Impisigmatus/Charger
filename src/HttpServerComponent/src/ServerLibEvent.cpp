#include <ServerLibEvent.hpp>
#include <ParserLibevent.hpp>

namespace Charger {
namespace HttpServer {

std::map<std::string, std::shared_ptr<IHandler>> ServerLibEvent::mHandlers;
std::string ServerLibEvent::M_NOT_FOUND  = ""
"<HTML>"
"  <HEAD>"
"    <TITLE>404 Not Found</TITLE>"
"  </HEAD>"
"  <BODY>"
"    <H1>Not Found</H1>"
"  </BODY>"
"</HTML>";

std::string ServerLibEvent::M_BAD_METHOD = ""
"<HTML>"
"  <HEAD>"
"    <TITLE>405 Method Not Allowed</TITLE>"
"  </HEAD>"
"  <BODY>"
"    <H1>Method Not Allowed</H1>"
"  </BODY>"
"</HTML>";

ServerLibEvent::ServerLibEvent(const std::string& host, const size_t port)
  : mListener(event_base_new(), &event_base_free)
  , mServer(evhttp_new(mListener.get()), &evhttp_free)
{
  evhttp_bind_socket(mServer.get(), host.c_str(), port);
  evhttp_set_gencb(mServer.get(), [](evhttp_request* request, void*) {
    reply(request, { HTTP_NOTFOUND, M_NOT_FOUND });
  }, nullptr);
}

bool ServerLibEvent::serve() const
{
  return event_base_dispatch(mListener.get());
}

void ServerLibEvent::addHandler(const std::string& path, const std::shared_ptr<IHandler>& handler) const
{
  mHandlers.insert({ path, handler });
  evhttp_set_cb(mServer.get(), path.c_str(), [](evhttp_request* request, void*) {
    Context context = {
      request->remote_host,
      ParserLibevent::getPath(request),
      ParserLibevent::getHeaders(request),
      ParserLibevent::getUriArgs(request),
      ParserLibevent::getBody(request)
    };

    auto handler = mHandlers[evhttp_uri_get_path(request->uri_elems)];
    switch (request->type)
    {
    case 1: // GET
      reply(request, handler->get(context));
      break;
    case 2: // POST
      reply(request, handler->post(context));
      break;
    case 8: // PUT
      reply(request, handler->put(context));
      break;
    case 16: // DELETE
      reply(request, handler->remove(context));
      break;
    default:
      reply(request, { HTTP_BADMETHOD, M_BAD_METHOD });
      return;
    }
  }, nullptr);
}

void ServerLibEvent::reply(evhttp_request* request, Response response)
{
  std::unique_ptr<evbuffer, decltype(&evbuffer_free)> buffer(evbuffer_new(), &evbuffer_free);
  evbuffer_add(buffer.get(), response.body.c_str(), response.body.length());
  evbuffer_add(buffer.get(), "\n", 1);
  evhttp_send_reply(request, response.code, "", buffer.get());
}

} // namespace HttpServer
} // namespace Charger
