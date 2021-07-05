#ifndef CHARGER_HTTP_CLIENT_REQUEST_HPP
#define CHARGER_HTTP_CLIENT_REQUEST_HPP

#include <Charger/NamedArgs/TagRegister.hpp>
#include <Charger/NamedArgs/Parser.hpp>

#include <map>
#include <string>

namespace Charger::Http::Client {

enum Param
{
  URL,
  HEADERS,
  GET_ARGS,
  DATA
};

namespace Arg {
using map = std::map<std::string, std::string>;
REGISTER_TAG(Param, URL,      std::string);
REGISTER_TAG(Param, HEADERS,  map);
REGISTER_TAG(Param, GET_ARGS, map);
REGISTER_TAG(Param, DATA,     std::string);
} // namespace Arguments

class Request
{
public:
  std::string getURL() const;
  std::map<std::string, std::string> getHeaders() const;
  std::map<std::string, std::string> getArgs() const;
  std::string getData() const;

  template<typename ...Args>
  void set(const Args&... args)
  {
    std::string url = Charger::NamedArgs::Parser<Param>::getOption<std::string>(Param::URL, args...);
    if (!url.empty())
      mURL = url;

    std::map<std::string, std::string> headers = Charger::NamedArgs::Parser<Param>::getOption<Arg::map>(Param::HEADERS, args...);
    if (!headers.empty())
      mHeaders = headers;

    std::map<std::string, std::string> params = Charger::NamedArgs::Parser<Param>::getOption<Arg::map>(Param::GET_ARGS, args...);
    if (!params.empty())
      mArgs = params;

    std::string data = Charger::NamedArgs::Parser<Param>::getOption<std::string>(Param::DATA, args...);
    if (!data.empty())
      mData = data;
  }

protected:
  std::string                        mURL;
  std::map<std::string, std::string> mHeaders;
  std::map<std::string, std::string> mArgs;
  std::string                        mData;

};

} // namespace Charger::Http::Client

#endif // CHARGER_HTTP_CLIENT_REQUEST_HPP
