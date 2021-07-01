#ifndef CHARGER_HTTP_SERVER_CONTEXT_HPP
#define CHARGER_HTTP_SERVER_CONTEXT_HPP

#include <string>
#include <vector>
#include <map>

namespace Charger::Http::Server {

/*!
 * \brief Модель в которой содержится контекст HTTP запроса
 */
class Context
{
public:
  /*!
   * \brief Конструктор с параметрами контекста
   * \param hostname Хост с которого получен запрос
   * \param path Путь к которому произошло обращение
   * \param headers Заголовки HTTP запроса
   * \param args GET-параметры запроса
   * \param body Тело запроса
   */
  Context(const std::string&                        hostname,
          const std::vector<std::string>&           path,
          const std::map<std::string, std::string>& headers,
          const std::map<std::string, std::string>& args,
          const std::string&                        body);

  // Геттеры
  std::string                        getHostname() const;
  std::vector<std::string>           getPath()     const;
  std::map<std::string, std::string> getHeaders()  const;
  std::map<std::string, std::string> getArgs()     const;
  std::string                        getBody()     const;


protected:
  std::string                        mHostname; //!< Хост с которого получен запрос
  std::vector<std::string>           mPath;     //!< Путь к которому произошло обращение
  std::map<std::string, std::string> mHeaders;  //!< Заголовки HTTP запроса
  std::map<std::string, std::string> mArgs;     //!< GET-параметры запроса
  std::string                        mBody;     //!< Тело запроса

};

} // namespace Charger::Http::Server

#endif // CHARGER_HTTP_SERVER_CONTEXT_HPP
