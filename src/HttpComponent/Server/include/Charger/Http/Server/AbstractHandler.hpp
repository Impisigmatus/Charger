#ifndef CHARGER_HTTP_SERVER_IHANDLER_HPP
#define CHARGER_HTTP_SERVER_IHANDLER_HPP

#include <Charger/Http/Server/Domain/Context.hpp>
#include <Charger/Http/Response.hpp>

namespace Charger::Http::Server {

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

} // namespace Charger::Http::Server

#endif // CHARGER_HTTP_SERVER_IHANDLER_HPP
