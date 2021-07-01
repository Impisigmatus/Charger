#ifndef CHARGER_HTTP_SERVER_RESPONSE_HPP
#define CHARGER_HTTP_SERVER_RESPONSE_HPP

#include <string>

namespace Charger::Http {

/*!
 * \brief Модель ответа на HTTP запрос
 */
class Response
{
public:
  /*!
    * \brief Конструктор с параметрами ответа
    * \param code Код HTTP ответа
    * \param reason Расшифровка кода HTTP ответа
    * \param body Тело ответа (по-умолчанию == reason)
    */
  Response(const size_t&      code,
           const std::string& reason,
           const std::string& body = "");

  /*!
   * \brief  Возвращает код HTTP ответа
   * \return size_t код HTTP ответа
   */
  size_t getCode() const;

  /*!
   * \brief  Возвращает расшифровку кода HTTP ответа
   * \return std::string расшифровка кода HTTP ответа
   */
  std::string getReason() const;

  /*!
   * \brief  Возвращает тело HTTP ответа
   * \return std::string тело HTTP ответа
   */
  std::string getBody() const;

private:
  int         mCode;   //!< Код HTTP ответа
  std::string mReason; //!< Расшифровка кода HTTP ответа
  std::string mBody;   //!< Тело ответа

};

} // namespace Charger::Http

#endif // CHARGER_HTTP_SERVER_RESPONSE_HPP
