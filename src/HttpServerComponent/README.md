# Компонент HTTP-сервера HttpServer

## 1. Что умеет?
Добаляет возможность обработки HTTP-запросов.

## 2. Зависимости
* libevent-dev

## 3. Как пользоваться?
Создаем по одному обработчику на каждый путь URI который мы хотим обрабатывать
```
#include <Charger/HttpServer/IHandler.hpp>

class Handler : public Charger::HttpServer::IHandler
{
public:
  Charger::HttpServer::Response post  (const Charger::HttpServer::Context& ctx) const override;
  Charger::HttpServer::Response put   (const Charger::HttpServer::Context& ctx) const override;
  Charger::HttpServer::Response get   (const Charger::HttpServer::Context& ctx) const override;
  Charger::HttpServer::Response remove(const Charger::HttpServer::Context& ctx) const override;

};

```

Добавляем реализацию обработчика:
* Получаем информацию из контекста
* На основе него производим некие действия
* Возвращаем ответ
```
#include "Handler.hpp"

Charger::HttpServer::Response Handler::post(const Charger::HttpServer::Context&) const
{
  // Что-то делаем
  return { 200, "OK", "тело" };
}

Charger::HttpServer::Response Handler::put(const Charger::HttpServer::Context&) const
{
  // Что-то делаем
  return { 200, "OK", "тело" };
}

Charger::HttpServer::Response Handler::get(const Charger::HttpServer::Context&) const
{
  // Что-то делаем
  return { 200, "OK", "тело" };
}

Charger::HttpServer::Response Handler::remove(const Charger::HttpServer::Context&) const
{
  // Что-то делаем
  return { 200, "OK", "тело" };
}
```
Тело ответа не обязательное. Если не переопределить метод, то он будет возвращать "Method Not Allowed".

Создаем сервер
```
auto server = std::make_shared<Charger::HttpServer::ServerLibEvent>("localhost", 8000);
```
Назначаем обработчики серверу
```
server->addHandler("/path", std::make_shared<Handler>());
```
Запускаем прослушку
```
return server->serve();
```
