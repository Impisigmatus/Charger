find_path(LIBEVENT_INCLUDE_DIR event.h
  PATHS
    /usr/local
    /opt
  PATH_SUFFIXES
    include
)

find_library(LIBEVENT_LIB
  NAMES
    event
  PATHS
    /usr/local
    /opt
  PATH_SUFFIXES
    lib
    lib64
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LibEvent REQUIRED_VARS
  LIBEVENT_INCLUDE_DIR
  LIBEVENT_LIB
)
