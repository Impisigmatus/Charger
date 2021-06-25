#ifndef CHARGER_HTTPSERVER_ISERVER_HPP
#define CHARGER_HTTPSERVER_ISERVER_HPP

#include <Charger/HttpServer/AbstractHandler.hpp>

#include <memory>

namespace Charger {
namespace HttpServer {

/*!
 * \brief Интерфейс HTTP сервера
 */
class IServer
{
public:
  IServer() = default;
  virtual ~IServer() = default;

public:
  /*!
   * \brief Метод начала прослушивания
   * \return int В случае успешного завершения прослушивания возвращает 0
   */
  virtual int serve() const = 0;

  /*!
   * \brief Добавляет класс-обработчик на определенный путь запроса
   * \param path Путь запроса для обработки обработчиком
   * \param handler Обработчик
   */
  virtual void addHandler(const std::string& path,
                          const std::shared_ptr<AbstractHandler>& handler) const = 0;

};

} // namespace HttpServer
} // namespace Charger

#endif // CHARGER_HTTPSERVER_ISERVER_HPP
