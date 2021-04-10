project(Charger LANGUAGES CXX)

if(CHARGER_ENABLE_NAMED_ARGS)
  add_subdirectory(NamedArgsComponent)
  list(APPEND components "NamedArgs")
endif(CHARGER_ENABLE_NAMED_ARGS)

message("Found the following ${PROJECT_NAME} components:")
foreach(component ${components})
  message("  ${component}")
endforeach()
