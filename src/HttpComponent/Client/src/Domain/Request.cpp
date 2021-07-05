#include <Domain/Request.hpp>

namespace Charger::Http::Client {

std::string Request::getURL() const
{
  return mURL;
}

std::map<std::string, std::string> Request::getHeaders() const
{
  return mHeaders;
}

std::map<std::string, std::string> Request::getArgs() const
{
  return mArgs;
}

std::string Request::getData() const
{
  return mData;
}

} // namespace Charger::Http::Client
