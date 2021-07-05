#ifndef CHARGER_HTTP_CLIENT_ISPEAKER_HPP
#define CHARGER_HTTP_CLIENT_ISPEAKER_HPP

#include <Charger/Http/Response.hpp>
#include <Charger/Http/Client/Domain/Request.hpp>

namespace Charger::Http::Client {

/*!
 * \brief Интерфейс HTTP клиента
 */
class ISpeaker
{
public:
  /*!
   * \brief Выполняет POST запрос
   * \param request Запрос
   * \return Charger::Http::Response Ответ
   */
  Response post(const Request& request) const;

  /*!
   * \brief Выполняет PUT запрос
   * \param request Запрос
   * \return Charger::Http::Response Ответ
   */
  Response put(const Request& request) const;

  /*!
   * \brief Выполняет GET запрос
   * \param request Запрос
   * \return Charger::Http::Response Ответ
   */
  Response get(const Request& request) const;

  /*!
   * \brief Выполняет DELETE запрос
   * \param request Запрос
   * \return Charger::Http::Response Ответ
   */
  Response remove(const Request& request) const;

  /*!
   * \brief Выполняет запрос
   * \param request Запрос
   * \param method Метод запроса
   * \return Charger::Http::Response Ответ
   */
  virtual Response custom(const Request& request, const::std::string& method) const = 0;

};

} // namespace Charger::Http::Client

#endif // CHARGER_HTTP_CLIENT_ISPEAKER_HPP
