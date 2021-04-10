project(ChargerLib LANGUAGES CXX)

cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 11)
set(IGNORE_QT_QMAKE_EXECUTABLE ${QT_QMAKE_EXECUTABLE})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

option(CHARGER_ENABLE_NAMED_ARGS  "Include NamedArgs component to build"  ON)
option(CHARGER_ENABLE_HTTP_SERVER "Include HttpServer component to build" ON)
option(CHARGER_BUILD_TESTS "Building tests" OFF)

add_subdirectory(src)

if (CHARGER_BUILD_TESTS)
  set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake_modules/)
  add_subdirectory(tests)
endif (CHARGER_BUILD_TESTS)
