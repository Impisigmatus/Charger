set(NAME "Client")
set(SUB_COMPONENT ${PROJECT_NAME}_${COMPONENT_NAME}_${NAME})

set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${SUB_COMPONENT}
  ${HEADERS}
  ${SOURCES}
)

target_link_libraries(${SUB_COMPONENT}
  PUBLIC
    Charger::NamedArgs
  PRIVATE
    ${CURL_LIBRARIES}
    Charger::Http
)

target_include_directories(${SUB_COMPONENT}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/${COMPONENT_NAME}/${NAME}
    ${CURL_INCLUDE_DIR}
)

add_library(${PROJECT_NAME}::${COMPONENT_NAME}::${NAME} ALIAS ${SUB_COMPONENT})
