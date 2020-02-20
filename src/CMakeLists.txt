project(Charger LANGUAGES CXX)

option(ENABLE_NAMED_ARGS "Include NamedArgs component to build" OFF)

if(ENABLE_NAMED_ARGS)
  add_subdirectory(NamedArgsComponent)
  list(APPEND components "named_args")
endif(ENABLE_NAMED_ARGS)

message("Found the following components:")
foreach(component ${components})
  message("  ${component}")
endforeach()
