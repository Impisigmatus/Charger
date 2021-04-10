#include <ParserLibevent.hpp>

#include <memory>
#include <sstream>

namespace Charger {
namespace HttpServer {

std::string ParserLibevent::getBody(const evhttp_request* request)
{
  auto input = request->input_buffer;
  auto length = evbuffer_get_length(input);
  if (length < 1)
    return std::string();

  std::shared_ptr<char[]> body;
  body.reset(new char[length]);
  evbuffer_copyout(input, body.get(), length);

  return body.get();
}

std::vector<std::string> ParserLibevent::getPath(const evhttp_request* request)
{
  std::vector<std::string> path;

  std::stringstream stream(evhttp_uri_get_path(request->uri_elems));
  for (std::string segment; getline(stream, segment, '/');)
    if (!segment.empty())
      path.push_back(segment);

  return path;
}

std::map<std::string, std::string> ParserLibevent::getUriArgs(const evhttp_request* request)
{
  struct evkeyvalq params;
  evhttp_parse_query(request->uri, &params);

  std::map<std::string, std::string> args;
  for (auto it = params.tqh_first; it != nullptr; it = it->next.tqe_next)
    args.insert({ it->key, it->value });
  evhttp_clear_headers(&params);

  return args;
}

std::map<std::string, std::string> ParserLibevent::getHeaders(const evhttp_request* /*request*/)
{
  return {}; // TODO: Добавить парсинг заголовков
}

} // namespace HttpServer
} // namespace Charger
