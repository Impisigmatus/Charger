# Компонент HTTP-сервера Http::Server

## 1. Что умеет?
Добаляет возможность обработки HTTP-запросов.

## 2. Зависимости
* libevent

## 3. Как пользоваться?
Создаем по одному обработчику на каждый путь URI который мы хотим обрабатывать
```
#include <Charger/Http/Server/AbstractHandler.hpp>

class Handler : public Charger::Http::Server::AbstractHandler
{
public:
  Charger::Http::Response post  (const Charger::Http::Server::Context& ctx) const override;
  Charger::Http::Response put   (const Charger::Http::Server::Context& ctx) const override;
  Charger::Http::Response get   (const Charger::Http::Server::Context& ctx) const override;
  Charger::Http::Response remove(const Charger::Http::Server::Context& ctx) const override;

};
```

Добавляем реализацию обработчика:
* Получаем информацию из контекста
* На основе него производим некие действия
* Возвращаем ответ
```
#include "Handler.hpp"

Charger::Http::Response Handler::post(const Charger::Http::Server::Context&) const
{
  // Что-то делаем
  return { 200, "OK", "тело" };
}

Charger::Http::Response Handler::put(const Charger::Http::Server::Context&) const
{
  // Что-то делаем
  return { 200, "OK", "тело" };
}

Charger::Http::Response Handler::get(const Charger::Http::Server::Context&) const
{
  // Что-то делаем
  return { 200, "OK", "тело" };
}

Charger::Http::Response Handler::remove(const Charger::Http::Server::Context&) const
{
  // Что-то делаем
  return { 200, "OK", "тело" };
}
```
Тело ответа не обязательное. Если не переопределить метод, то он будет возвращать "Method Not Allowed".

```
// Создаем сервер
auto server = std::make_shared<Charger::HttpServer::ServerLibEvent>("localhost", 8000);

// Назначаем обработчики серверу
server->addHandler("/path", std::make_shared<Handler>());

// Запускаем прослушку
server->serve();

// Останавливаем прослушку
server->stop();
```
