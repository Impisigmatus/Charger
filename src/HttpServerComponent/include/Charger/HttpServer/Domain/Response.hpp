#ifndef CHARGER_HTTPSERVER_RESPONSE_HPP
#define CHARGER_HTTPSERVER_RESPONSE_HPP

#include <string>

namespace Charger {
namespace HttpServer {

/*!
 * \brief Модель ответа на HTTP запрос
 */
struct Response
{
public:
  int         code;   //!< Код HTTP ответа
  std::string reason; //!< Расшифровка кода HTTP ответа
  std::string body;   //!< Тело ответа

};

} // namespace HttpServer
} // namespace Charger

#endif // CHARGER_HTTPSERVER_RESPONSE_HPP
