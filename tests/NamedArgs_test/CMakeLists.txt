getProjectName(NAME)
project(${NAME})

add_executable(${PROJECT_NAME})
make_gtest(${PROJECT_NAME})

#target_link_libraries(${PROJECT_NAME}
#  PRIVATE
#    Charger::NamedArgs
#)
