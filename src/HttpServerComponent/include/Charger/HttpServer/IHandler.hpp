#ifndef CHARGER_HTTPSERVER_IHANDLER_HPP
#define CHARGER_HTTPSERVER_IHANDLER_HPP

#include <Charger/HttpServer/Domain/Context.hpp>
#include <Charger/HttpServer/Domain/Response.hpp>

namespace Charger {
namespace HttpServer {

/*!
 * \brief Интерфейс обработчика для запрашиваемого пути
 */
class IHandler
{
public:
  IHandler() = default;
  virtual ~IHandler() = default;

public:
  /*!
   * \brief Метод обработки POST метода
   * \param ctx Контекст запроса
   * \return Charger::HttpServer::Response Ответ отправляемый клиенту
   */
  virtual const Response post(const Context& ctx) const = 0;

  /*!
   * \brief Метод обработки PUT метода
   * \param ctx Контекст запроса
   * \return Charger::HttpServer::Response Ответ отправляемый клиенту
   */
  virtual const Response put(const Context& ctx) const = 0;

  /*!
   * \brief Метод обработки GET метода
   * \param ctx Контекст запроса
   * \return Charger::HttpServer::Response Ответ отправляемый клиенту
   */
  virtual const Response get(const Context& ctx) const = 0;

  /*!
   * \brief Метод обработки REMOVE метода
   * \param ctx Контекст запроса
   * \return Charger::HttpServer::Response Ответ отправляемый клиенту
   */
  virtual const Response remove(const Context& ctx) const = 0;

};

} // namespace HttpServer
} // namespace Charger

#endif // CHARGER_HTTPSERVER_IHANDLER_HPP
