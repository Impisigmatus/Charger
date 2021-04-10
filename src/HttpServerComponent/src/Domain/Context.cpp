#include <Domain/Context.hpp>

namespace Charger {
namespace HttpServer {

Context::Context(const std::string&                        hostname,
                 const std::vector<std::string>&           path,
                 const std::map<std::string, std::string>& headers,
                 const std::map<std::string, std::string>& args,
                 const std::string&                        body)
  : mHostname (hostname)
  , mPath     (path)
  , mHeaders  (headers)
  , mArgs     (args)
  , mBody     (body)
{}

std::string Context::getHostname() const
{
  return mHostname;
}

std::vector<std::string> Context::getPath() const
{
  return mPath;
}

std::map<std::string, std::string> Context::getHeaders() const
{
  return mHeaders;
}

std::map<std::string, std::string> Context::getArgs() const
{
  return mArgs;
}

std::string Context::getBody() const
{
  return mBody;
}

} // namespace HttpServer
} // namespace Charger
