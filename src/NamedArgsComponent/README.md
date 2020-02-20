# Компонент именовынных аргументов NamedArguments

## 1. Что умеет?
Добаляет возможность регистрации и использования именованных аругментов.

## 2. Зависимости
Не использует внешние зависимост. Реализация полностью на стандартной библиотеке C++.

## 3. Что такое именованные аргументы?
Именованные аргументы, это аргументы, порядок которых не важен и при их указании, им присваивается имя. Например:
```
obj.configure(Arguments::AGE       = "29",
              Arguments::NAME      = "John",
              Arguments::LAST_NAME = "Doe");
```

## 4. Где может быть полезно?
В классах где необходимо конфигурирование (например параметры подключения к серверу).

## 5. Как пользоваться?
### 5.1 Регистрация именованных аргументов
Делаем forward declaration для нашего будущего перечисления имен аргументов и задаем TAG_MACRO для указания рабочего перечисления.
```
enum class Param;
#define TAG_MACRO Param
#include <Charger/NamedArgs/TagRegister.hpp>
#include <Charger/NamedArgs/Parser.hpp>
```

Создаем перечисление в котором будут перечислены все возможные имена аргументов(enum **class** обязателен для forward declaration):
```
enum class Param
{
  AGE,
  NAME,
  LAST_NAME
};
```

В необходимом пространстве имен регистрируем наши именованные аргументы:
```
namespace Arguments {
REGISTER_TAG(AGE,       size_t);
REGISTER_TAG(NAME,      std::string);
REGISTER_TAG(LAST_NAME, std::string);
} // namespace Arguments
```

Убираем определение TAG_MACRO:
```
#undef TAG_MACRO
```

### 5.2 Использование именованных аргументов
Пишем метод(функцию) с пееременным числом аргументов(Variadic template) в котором с помощью статического метода парсинга получаем из пакета нужные данные(Если имя аргумента не найдено  полученном пакете, то он определится конструктором по-умолчанию):
```
template<typename ...Args>
void configure(const Args&... args)
{
  set(Charger::NamedArgs::Parser::getOption<size_t>     (Param::AGE,       args...),
      Charger::NamedArgs::Parser::getOption<std::string>(Param::NAME,      args...),
      Charger::NamedArgs::Parser::getOption<std::string>(Param::LAST_NAME, args...));
}
```

Для вызова метода с именованными аргументами указываем его имя и значение:
```
obj.configure(Arguments::LAST_NAME = LAST_NAME,
              Arguments::AGE       = AGE,
              Arguments::NAME      = NAME);
```
