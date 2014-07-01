cmake_minimum_required (VERSION 2.6)
project (Tutorial)

message ("srcdir:${PROJECT_SOURCE_DIR}")
message ("bindir:${PROJECT_BINARY_DIR}")

# should we use our own math functions?
option (USE_MYMATH "Use tutorial provided math implementation" ON)

# The Version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 4)

#does this system provide the log an exp functions?
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(
	"${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
	"${PROJECT_BINARY_DIR}/TutorialConfig.h"
	)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories ("${PROJECT_BINARY_DIR}")

# add the MathFunctions library?
if (USE_MYMATH)
	include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
	add_subdirectory (MathFunctions)
	set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# add the executable
add_executable (tutorial tutorial.cpp)
target_link_libraries (tutorial ${EXTRA_LIBS})

# for install
install (TARGETS tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
	DESTINATION include)
set (CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}")

# for tests
enable_testing ()
add_test (tutorial25 tutorial 25)
set_tests_properties (tutorial25
	PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")

# for packing
# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE  
     "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include (CPack)
