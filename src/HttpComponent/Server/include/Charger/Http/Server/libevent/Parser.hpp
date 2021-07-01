#ifndef CHARGER_HTTP_SERVER_LIBEVENT_PARSER_HPP
#define CHARGER_HTTP_SERVER_LIBEVENT_PARSER_HPP

#include <evhttp.h>

#include <map>
#include <vector>
#include <string>

namespace Charger::Http::Server::libevent {

/*!
 * \brief Класс для разбора контекста для сервера на libevent
 */
class Parser
{
public:
  /*!
   * \brief Получение пути обращения
   * \details Разбивает путь на сегменты
   * \param request Запрос
   * \return std::vector<std::string> Путь обращения
   */
  static std::vector<std::string> getPath(const struct evhttp_request* request);

  /*!
   * \brief Получение GET-параметров запроса
   * \details Возвращаемые параметры имеют вид <ключ, значение>
   * \param request Запрос
   * \return std::map<std::string, std::string> GET--параметры
   */
  static std::map<std::string, std::string> getUriArgs(const struct evhttp_request* request);

  /*!
   * \brief Получение заголовков запроса
   * \details Возвращаемые параметры имеют вид <название_заголовка, значение_заголовка>
   * \param request Запрос
   * \return std::map<std::string, std::string> Заголовки запроса
   */
  static std::map<std::string, std::string> getHeaders(const struct evhttp_request* request);

  /*!
   * \brief Получение тела запроса
   * \param request Запрос
   * \return std::string Тело запроса
   */
  static std::string getBody(const struct evhttp_request* request);

};

} // namespace Charger::Http::Server::libevent

#endif // CHARGER_HTTP_SERVER_LIBEVENT_PARSER_HPP
