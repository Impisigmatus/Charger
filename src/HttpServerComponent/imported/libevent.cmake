find_package(LibEvent REQUIRED)

add_library(libevent STATIC IMPORTED GLOBAL)

set_target_properties(libevent PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${LIBEVENT_INCLUDE_DIR})
set_target_properties(libevent PROPERTIES IMPORTED_LOCATION ${LIBEVENT_LIB})
