set(Name "Client")
set(Component ${PROJECT_NAME}_Http_${Name})

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${Component}
  ${HEADERS}
  ${SOURCES}
)

target_include_directories(${Component}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/Http/${Name}
)

add_library(${PROJECT_NAME}::Http::${Name} ALIAS ${Component})
