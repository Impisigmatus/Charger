#include <Domain/Response.hpp>

namespace Charger {
namespace HttpServer {

Response::Response(const size_t& code, const std::string& reason, const std::string& body)
  : mCode   (code)
  , mReason (reason)
  , mBody   (body)
{
  if (mBody.empty())
    mBody = mReason;
}

size_t Response::getCode() const
{
  return mCode;
}

std::string Response::getReason() const
{
  return mReason;
}

std::string Response::getBody() const
{
  return mBody;
}

} // namespace HttpServer
} // namespace Charger
