# Библиотека Charger
Собрание компонентов для решения типовых задач и упрощения разработки программного обеспечения.

# Как использовать?
## Добавляем код к проекту
### Subtree
Добавить subtree
```
$ git remote add -f charger git@github.com:Impisigmatus/Charger.git
$ git subtree add --squash -P dependencies/Charger charger dev
```
Обновить subtree
```
$ git fetch charger dev
$ git subtree merge --squash -P dependencies/Charger charger/dev
```
dependencies/CMakeLists.txt
```
add_subdirectory(Charger)
```

### 3rdparty
Копируем код проекта в 3rdparty/

3rdparty/CMakeLists.txt
```
add_subdirectory(Charger)
```

## Линкуем
Включаем в CMake опциях компоненты которые нам необходимы.

Доступные компоненты:
* [NamedArgs](src/NamedArgsComponent/README.md) (CHARGER_ENABLE_NAMED_ARGS) для добавления возможности использования именованных аргументов;
* [Http::Server](src/HttpComponent/Server/README.md)  (CHARGER_ENABLE_HTTP_SERVER) для добавления возможности обработки HTTP-запросов;
* [Http::Client](src/HttpComponent/Client/README.md)  (CHARGER_ENABLE_HTTP_CLIENT) для добавления возможности обработки HTTP-запросов;

И линкуем нужные компоненты
```
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Charger::HttpServer
)
```

## TODO
В данный момент планируется реализация компонентов:
* ProgramOptions для добавления возможности конфигурирования приложения;
* Terminator для добавления возможности корректного прерывания исполнения методов;
