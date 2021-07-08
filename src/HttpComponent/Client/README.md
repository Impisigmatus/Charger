# Компонент HTTP-клиента Http::Client

## 1. Что умеет?
Добаляет возможность отправки HTTP-запросов.

## 2. Зависимости
* libcurl

## 3. Как пользоваться?
```
// Создаем клиент 
Charger::Http::Client::curl::Speaker client;

// Создаем запрос
Charger::Http::Client::Request request;

// Конфигурируем запрос
request.set(Charger::Http::Client::Arg::URL      = "localhost:8000",
            Charger::Http::Client::Arg::HEADERS  = headers,
            Charger::Http::Client::Arg::GET_ARGS = args,
            Charger::Http::Client::Arg::DATA     = "body");

// Меняем одну из опций запроса (при необходимости)
request.set(Charger::Http::Client::Arg::URL = "localhost:8000/path");

// Выполняем запрос
auto response = client.post(request);
```