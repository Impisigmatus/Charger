#ifndef CHARGER_HTTPSERVER_RESPONSE_HPP
#define CHARGER_HTTPSERVER_RESPONSE_HPP

#include <string>

namespace Charger {
namespace HttpServer {

/*!
 * \brief Модель ответа на HTTP запрос
 */
class Response
{
public:
  /*!
   * \brief Конструктор с параметрами ответа
   * \param code Код HTTP ответа
   * \param description Расшифровка кода HTTP ответа
   * \param body Тело ответа
   */
  Response(const int&         code,
           const std::string& description,
           const std::string& body);

  /*!
   * \brief Конвертирует HTTP ответ в строку
   * \details Собирает HTML страничку ответа
   * \return std::string Строка HTTP ответа
   */
  std::string toString() const;

  //! Возвращает код HTTP ответа
  int getCode() const;

private:
  int         mCode;        //!< Код HTTP ответа
  std::string mDescription; //!< Расшифровка кода HTTP ответа
  std::string mBody;        //!< Тело ответа

};

} // namespace HttpServer
} // namespace Charger

#endif // CHARGER_HTTPSERVER_RESPONSE_HPP
