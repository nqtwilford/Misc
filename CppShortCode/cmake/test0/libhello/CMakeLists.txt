project(libhello)
set(LIB_SRC hello.c hello.h)
add_definitions("-DLIBHELLO_BUILD")
add_library(libhello SHARED ${LIB_SRC})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set_target_properties(libhello PROPERTIES OUTPUT_NAME "hello")
install(TARGETS libhello DESTINATION bin)
set(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}")
