function (make_gtest TARGET_NAME)
  find_package(GTest REQUIRED)

  file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
  target_sources(${TARGET_NAME} PRIVATE ${SOURCES})

  target_link_libraries(${TARGET_NAME} PRIVATE ${GTEST_LIBRARIES})
  target_include_directories(${TARGET_NAME} PRIVATE ${GTEST_INCLUDE_DIRS})
endfunction()

function (getProjectName RESULT)
  string(REGEX MATCH [a-zA-Z0-9]+_test NAME ${CMAKE_CURRENT_SOURCE_DIR})
  set(${RESULT} ${NAME} PARENT_SCOPE)
endfunction()
