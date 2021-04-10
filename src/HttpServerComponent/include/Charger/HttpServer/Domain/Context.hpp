#ifndef HTTPSERVER_CONTEXT_HPP
#define HTTPSERVER_CONTEXT_HPP

#include <string>
#include <vector>
#include <map>

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

#endif // HTTPSERVER_CONTEXT_HPP
