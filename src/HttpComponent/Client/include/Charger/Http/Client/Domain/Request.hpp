#ifndef CHARGER_HTTP_CLIENT_REQUEST_HPP
#define CHARGER_HTTP_CLIENT_REQUEST_HPP

#include <Charger/NamedArgs/TagRegister.hpp>
#include <Charger/NamedArgs/Parser.hpp>

#include <map>
#include <string>

namespace Charger::Http::Client {

enum Param
{
  URL,
  HEADERS,
  GET_ARGS,
  DATA
};

namespace Arg {
using map = std::map<std::string, std::string>;
REGISTER_TAG(Param, URL,      std::string);
REGISTER_TAG(Param, HEADERS,  map);
REGISTER_TAG(Param, GET_ARGS, map);
REGISTER_TAG(Param, DATA,     std::string);
} // namespace Arg

/*!
 * \brief Модель HTTP запроса
 */
class Request
{
public:
  /*!
   * \brief Возвращает адрес запроса
   * \return std::string Адрес запроса
   */
  std::string getURL() const;

  /*!
   * \brief Возвращает заголовки запроса
   * \return std::map<std::string, std::string> Таблица заголовков запроса <заголовок, значение>
   */
  std::map<std::string, std::string> getHeaders() const;

  /*!
   * \brief Возвращает GET параметры запроса
   * \return std::map<std::string, std::string> Таблица GET параметров запроса <ключ, значение>
   */
  std::map<std::string, std::string> getArgs() const;

  /*!
   * \brief Возвращает тело запроса
   * \return std::string Тело запроса
   */
  std::string getData() const;

  /*!
   * \brief Шаблонная функция конфигурирования запроса использующая именованные аргументы
   * \details Вариативный шаблон требует записи вида
   * Charger::Http::Client::Arg::<имя аргумента> = <значение аргумента> перечисленных через запятую
   * \param args Вариативный шаблон
   */
  template<typename ...Args>
  void set(const Args&... args)
  {
    std::string url = Charger::NamedArgs::Parser<Param>::getOption<std::string>(Param::URL, args...);
    if (!url.empty())
      mURL = url;

    std::map<std::string, std::string> headers = Charger::NamedArgs::Parser<Param>::getOption<Arg::map>(Param::HEADERS, args...);
    if (!headers.empty())
      mHeaders = headers;

    std::map<std::string, std::string> params = Charger::NamedArgs::Parser<Param>::getOption<Arg::map>(Param::GET_ARGS, args...);
    if (!params.empty())
      mArgs = params;

    std::string data = Charger::NamedArgs::Parser<Param>::getOption<std::string>(Param::DATA, args...);
    if (!data.empty())
      mData = data;
  }

protected:
  std::string                        mURL;
  std::map<std::string, std::string> mHeaders;
  std::map<std::string, std::string> mArgs;
  std::string                        mData;

};

} // namespace Charger::Http::Client

#endif // CHARGER_HTTP_CLIENT_REQUEST_HPP
