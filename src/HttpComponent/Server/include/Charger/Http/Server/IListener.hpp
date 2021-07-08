#ifndef CHARGER_HTTP_SERVER_ILISTENER_HPP
#define CHARGER_HTTP_SERVER_ILISTENER_HPP

#include <Charger/Http/Server/AbstractHandler.hpp>

#include <memory>

namespace Charger::Http::Server {

/*!
 * \brief Интерфейс HTTP сервера
 */
class IListener
{
public:
  IListener() = default;
  virtual ~IListener() = default;

public:
  /*!
   * \brief Запуск асинхронного прослушивания
   */
  virtual void serve() const = 0;

  /*!
   * \brief Остановка асинхронного прослушивания
   */
  virtual void stop() const = 0;

  /*!
   * \brief Добавляет класс-обработчик на определенный путь запроса
   * \param path Путь запроса для обработки обработчиком
   * \param handler Обработчик
   */
  virtual void addHandler(const std::string& path,
                          const std::shared_ptr<AbstractHandler>& handler) const = 0;

};

} // namespace Charger::Http::Server

#endif // CHARGER_HTTP_SERVER_ILISTENER_HPP
