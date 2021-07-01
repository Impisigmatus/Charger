project(Charger LANGUAGES CXX)

if(CHARGER_ENABLE_NAMED_ARGS)
  add_subdirectory(NamedArgsComponent)
  list(APPEND components "NamedArgs")
endif(CHARGER_ENABLE_NAMED_ARGS)

if(CHARGER_ENABLE_HTTP_SERVER)
  list(APPEND components "Http::Server")
endif(CHARGER_ENABLE_HTTP_SERVER)

if(CHARGER_ENABLE_HTTP_CLIENT)
  list(APPEND components "Http::Client")
endif(CHARGER_ENABLE_HTTP_CLIENT)

add_subdirectory(HttpComponent)

message("Found the following ${PROJECT_NAME} components:")
foreach(component ${components})
  message("  ${component}")
endforeach()
