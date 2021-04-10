#ifndef CHARGER_HTTPSERVER_CONTEXT_HPP
#define CHARGER_HTTPSERVER_CONTEXT_HPP

#include <string>
#include <vector>
#include <map>

namespace Charger {
namespace HttpServer {

class Context
{
public:
  Context(const std::string&                        hostname,
          const std::vector<std::string>&           path,
          const std::map<std::string, std::string>& headers,
          const std::map<std::string, std::string>& args,
          const std::string&                        body);

  std::string                        getHostname() const;
  std::vector<std::string>           getPath()     const;
  std::map<std::string, std::string> getHeaders()  const;
  std::map<std::string, std::string> getArgs()     const;
  std::string                        getBody()     const;


protected:
  std::string                        mHostname;
  std::vector<std::string>           mPath;
  std::map<std::string, std::string> mHeaders;
  std::map<std::string, std::string> mArgs;
  std::string                        mBody;

};

} // namespace HttpServer
} // namespace Charger

#endif // CHARGER_HTTPSERVER_CONTEXT_HPP
