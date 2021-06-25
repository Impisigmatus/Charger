#include <libevent/Parser.hpp>

#include <memory>
#include <sstream>

namespace Charger {
namespace HttpServer {
namespace libevent {

std::vector<std::string> Parser::getPath(const evhttp_request* request)
{
  std::vector<std::string> path;

  std::stringstream stream(evhttp_uri_get_path(request->uri_elems));
  for (std::string segment; getline(stream, segment, '/');)
    if (!segment.empty())
      path.push_back(segment);

  return path;
}

std::map<std::string, std::string> Parser::getUriArgs(const evhttp_request* request)
{
  struct evkeyvalq params;
  evhttp_parse_query(request->uri, &params);

  std::map<std::string, std::string> args;
  for (auto it = params.tqh_first; it != nullptr; it = it->next.tqe_next)
    args.insert({ it->key, it->value });
  evhttp_clear_headers(&params);

  return args;
}

std::map<std::string, std::string> Parser::getHeaders(const evhttp_request* request)
{
  std::unique_ptr<evkeyvalq, decltype(&evhttp_clear_headers)> raw(request->input_headers, &evhttp_clear_headers);

  std::map<std::string, std::string> headers;
  for (auto it = raw->tqh_first; it != nullptr; it = it->next.tqe_next)
    headers.insert({ it->key, it->value });

  return headers;
}

std::string Parser::getBody(const evhttp_request* request)
{
  auto input = request->input_buffer;
  auto length = evbuffer_get_length(input);
  if (!length)
    return std::string();

  std::shared_ptr<char[]> body;
  body.reset(new char[length]);
  evbuffer_copyout(input, body.get(), length);

  return body.get();
}

} // namespace libevent
} // namespace HttpServer
} // namespace Charger
