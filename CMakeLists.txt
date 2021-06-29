project(ChargerLib LANGUAGES CXX)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(IGNORE_QT_QMAKE_EXECUTABLE ${QT_QMAKE_EXECUTABLE})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)
if(IS_SUBPROJECT)
  message(STATUS "${PROJECT_NAME} has a parent scope.")
  set(DEFAULT_OPT OFF)
else()
  message(STATUS "${PROJECT_NAME} doesn't have a parent scope.")
  set(DEFAULT_OPT ON)
endif()

option(CHARGER_ENABLE_NAMED_ARGS  "Include NamedArgs component to build"  ${DEFAULT_OPT})
option(CHARGER_ENABLE_HTTP_SERVER "Include HttpServer component to build" ${DEFAULT_OPT})
option(CHARGER_BUILD_TESTS        "Building tests"                        ${DEFAULT_OPT})

add_subdirectory(src)

if (CHARGER_BUILD_TESTS)
  set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake_modules/)
  add_subdirectory(tests)
endif (CHARGER_BUILD_TESTS)
