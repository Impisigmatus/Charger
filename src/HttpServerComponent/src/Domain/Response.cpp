#include <Domain/Response.hpp>

#include <sstream>

namespace Charger {
namespace HttpServer {

Response::Response(const int&         code,
                   const std::string& description,
                   const std::string& body)
  : mCode        (code)
  , mDescription (description)
  , mBody        (body)
{}

std::string Response::toString() const
{
  std::stringstream stream;
  stream << "<HTML>"
            "  <HEAD>"
            "    <TITLE>" << mCode << " " << mDescription << "</TITLE>"
            "  </HEAD>"
            "  <BODY>"
            "    <H1>" << mBody << "</H1>"
            "  </BODY>"
            "</HTML>";
  return stream.str();
}

int Response::getCode() const
{
  return mCode;
}

} // namespace HttpServer
} // namespace Charger
