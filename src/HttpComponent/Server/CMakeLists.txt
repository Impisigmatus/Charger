set(NAME "Server")
set(SUB_COMPONENT ${PROJECT_NAME}_${COMPONENT_NAME}_${NAME})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules")

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${SUB_COMPONENT}
  ${HEADERS}
  ${SOURCES}
)

target_link_libraries(${SUB_COMPONENT}
  PUBLIC
    libevent
    Charger::Http
)

target_include_directories(${SUB_COMPONENT}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/${COMPONENT_NAME}/${NAME}
)

add_library(${PROJECT_NAME}::${COMPONENT_NAME}::${NAME} ALIAS ${SUB_COMPONENT})

add_subdirectory(imported)
