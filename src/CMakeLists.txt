project(Charger LANGUAGES CXX)

if(CHARGER_ENABLE_NAMED_ARGS)
  add_subdirectory(NamedArgsComponent)
  list(APPEND components "NamedArgs")
endif(CHARGER_ENABLE_NAMED_ARGS)

if(CHARGER_ENABLE_HTTP_SERVER)
  add_subdirectory(HttpServerComponent)
  list(APPEND components "HttpServer")
endif(CHARGER_ENABLE_HTTP_SERVER)

message("Found the following ${PROJECT_NAME} components:")
foreach(component ${components})
  message("  ${component}")
endforeach()
