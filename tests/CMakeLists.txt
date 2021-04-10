include(gtest)

if (UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif (UNIX)

add_subdirectory(NamedArgs_test)
