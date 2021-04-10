#include <Domain/Response.hpp>

#include <sstream>

namespace Charger {
namespace HttpServer {

std::string Response::toString() const
{
  std::stringstream stream;

  stream << "<HTML>"
            "  <HEAD>"
            "    <TITLE>" << code << " " << description << "</TITLE>"
            "  </HEAD>"
            "  <BODY>"
            "    <H1>" << body << "</H1>"
            "  </BODY>"
            "</HTML>";

  return stream.str();
}

} // namespace HttpServer
} // namespace Charger
