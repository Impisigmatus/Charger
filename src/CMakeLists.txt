project(Charger LANGUAGES CXX)

option(ENABLE_NAMED_ARGS        "Include NamedArgs component to build"       OFF)
option(ENABLE_COMMAND_LINE_ARGS "Include CommandLineArgs component to build" OFF)

if(ENABLE_NAMED_ARGS)
  add_subdirectory(NamedArgsComponent)
  list(APPEND components "named_args")
endif(ENABLE_NAMED_ARGS)

if(ENABLE_COMMAND_LINE_ARGS)
  add_subdirectory(CommandLineArgsComponent)
  list(APPEND components "command_line_args")
endif(ENABLE_COMMAND_LINE_ARGS)

message("Found the following components:")
foreach(component ${components})
  message("  ${component}")
endforeach()
