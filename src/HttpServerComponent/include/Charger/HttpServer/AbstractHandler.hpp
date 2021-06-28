#ifndef CHARGER_HTTPSERVER_IHANDLER_HPP
#define CHARGER_HTTPSERVER_IHANDLER_HPP

#include <Charger/HttpServer/Domain/Context.hpp>
#include <Charger/HttpServer/Domain/Response.hpp>

namespace Charger {
namespace HttpServer {

/*!
 * \brief Абстрактный класс обработчика для запрашиваемого пути
 * \details Не реализованные методы будут возвращать 405 Method Not Allowed
 */
class AbstractHandler
{
public:
  AbstractHandler() = default;
  virtual ~AbstractHandler() = default;

public:
  /*!
   * \brief Метод обработки POST метода
   * \param ctx Контекст запроса
   * \return Charger::HttpServer::Response Ответ отправляемый клиенту
   */
  virtual Response post(const Context& ctx) const;

  /*!
   * \brief Метод обработки PUT метода
   * \param ctx Контекст запроса
   * \return Charger::HttpServer::Response Ответ отправляемый клиенту
   */
  virtual Response put(const Context& ctx) const;

  /*!
   * \brief Метод обработки GET метода
   * \param ctx Контекст запроса
   * \return Charger::HttpServer::Response Ответ отправляемый клиенту
   */
  virtual Response get(const Context& ctx) const;

  /*!
   * \brief Метод обработки REMOVE метода
   * \param ctx Контекст запроса
   * \return Charger::HttpServer::Response Ответ отправляемый клиенту
   */
  virtual Response remove(const Context& ctx) const;

};

} // namespace HttpServer
} // namespace Charger

#endif // CHARGER_HTTPSERVER_IHANDLER_HPP
