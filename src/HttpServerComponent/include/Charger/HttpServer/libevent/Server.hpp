#ifndef CHARGER_HTTPSERVER_SERVER_LIBEVENT_HPP
#define CHARGER_HTTPSERVER_SERVER_LIBEVENT_HPP

#include <Charger/HttpServer/IServer.hpp>

#include <evhttp.h>

namespace Charger {
namespace HttpServer {
namespace libevent {

/*!
 * \brief Класс реализации HTTP сервера средствами libevent
 */
class Server : public IServer
{
public:
  /*!
   * \brief Конкструктор с параметрами запуска сервера
   * \param host Хост на котором работает сервер
   * \param port Порт на котором сервер будет слушать запросы
   */
  Server(const std::string& host, const size_t port);

  int serve() const override;
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

private:
  static std::map<std::string, std::shared_ptr<AbstractHandler>> mHandlers; //!< Обработчики

};

} // namespace libevent
} // namespace HttpServer
} // namespace Charger

#endif // HTTPSERVER_SERVER_LIBEVENT_HPP
