set(Name "CommandLineArgs")
set(Component ${PROJECT_NAME}_${Name})

find_package(Boost REQUIRED
  COMPONENTS
    program_options
)

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${Component}
  ${HEADERS}
  ${SOURCES}
)

include(GenerateExportHeader)
generate_export_header(${Component})

target_link_libraries(${Component}
  PRIVATE
    ${Boost_LIBRARIES}
)

target_include_directories(${Component}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/${Name}
)

add_library(${PROJECT_NAME}::${Name} ALIAS ${Component})
