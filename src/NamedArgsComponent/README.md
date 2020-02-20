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
Подключаем заголовочные файлы:
```
#include <Charger/NamedArgs/TagRegister.hpp> // Для регистрации именованных аргументов
#include <Charger/NamedArgs/Parser.hpp> // Для разбора Variadic template на  необходимые параметры
```

Создаем перечисление в котором будут перечислены все возможные имена аргументов:
```
enum Param
{
  AGE,
  NAME,
  LAST_NAME
};
```

В необходимом пространстве имен регистрируем наши именованные аргументы(Первым параметром макроса идет наше перечисление, далее имя аргумента и последним тип аргумента):
```
namespace Arguments {
REGISTER_TAG(Param, AGE,       size_t);
REGISTER_TAG(Param, NAME,      std::string);
REGISTER_TAG(Param, LAST_NAME, std::string);
} // namespace Arguments
```

### 5.2 Использование именованных аргументов
Пишем метод(функцию) с пееременным числом аргументов(**Variadic template**) в котором с помощью статического метода парсинга получаем из пакета нужные данные(Если имя аргумента не найдено  полученном пакете, то он определится конструктором по-умолчанию):
```
template<typename ...Args>
void configure(const Args&... args)
{
  set(Charger::NamedArgs::Parser<Param>::getOption<size_t>     (Param::AGE,       args...),
      Charger::NamedArgs::Parser<Param>::getOption<std::string>(Param::NAME,      args...),
      Charger::NamedArgs::Parser<Param>::getOption<std::string>(Param::LAST_NAME, args...));
}
```

Для вызова метода с именованными аргументами указываем его имя и значение:
```
obj.configure(Arguments::LAST_NAME = LAST_NAME,
              Arguments::AGE       = AGE,
              Arguments::NAME      = NAME);
```
