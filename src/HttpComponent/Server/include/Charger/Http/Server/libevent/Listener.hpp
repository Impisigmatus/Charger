#ifndef CHARGER_HTTP_SERVER_LIBEVENT_LISTENER_HPP
#define CHARGER_HTTP_SERVER_LIBEVENT_LISTENER_HPP

#include <Charger/Http/Server/IListener.hpp>

#include <evhttp.h>

#include <thread>

namespace Charger::Http::Server::libevent {

/*!
 * \brief Класс реализации HTTP сервера средствами libevent
 */
class Listener : public IListener
{
public:
  /*!
   * \brief Конкструктор с параметрами запуска сервера
   * \param host Хост на котором работает сервер
   * \param port Порт на котором сервер будет слушать запросы
   */
  Listener(const std::string& host, const size_t port);

  void serve() const override;
  void stop() const override;
  void addHandler(const std::string& path,
                  const std::shared_ptr<AbstractHandler>& handler) const override;

protected:
  /*!
   * \brief Ответить клиенту
   * \param request Запрос от клиента
   * \param response Ответ клиенту
   */
  static void reply(struct evhttp_request* request, const Response& response);

private:
  std::unique_ptr<event_base, decltype(&event_base_free)> mListener;
  std::unique_ptr<evhttp,     decltype(&evhttp_free)>     mServer;

  mutable std::unique_ptr<std::thread> mThread;

private:
  static std::map<std::string, std::shared_ptr<AbstractHandler>> mHandlers; //!< Обработчики

};

} // namespace Charger::Http::Server::libevent

#endif // CHARGER_HTTP_SERVER_LIBEVENT_LISTENER_HPP
