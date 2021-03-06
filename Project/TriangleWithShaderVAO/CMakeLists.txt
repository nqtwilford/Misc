cmake_minimum_required(VERSION 2.8)

add_definitions(-DGLEW_STATIC)

set(CMAKE_INCLUDE_PATH $ENV{GLEW_ROOT}/include)
set(CMAKE_LIBRARY_PATH $ENV{GLEW_ROOT}/lib/Release/Win32)
find_package(GLEW REQUIRED)
if(GLEW_FOUND)
	include_directories(${GLEW_INCLUDE_DIR})
	message(${GLEW_INCLUDE_DIR})
	message(${GLEW_LIBRARY})
endif()

set(GLUT_ROOT_PATH $ENV{GLUT_ROOT})
find_package(GLUT REQUIRED)
if(GLUT_FOUND)
	include_directories(${GLUT_INCLUDE_DIR})
	message(${GLUT_INCLUDE_DIR})
	message(${GLUT_glut_LIBRARY})
endif()

set(SRC main.cpp textfile.h textfile.cpp)
add_executable(main ${SRC})
#target_link_libraries(main ${GLEW_LIBRARY} ${GLUT_glut_LIBRARY} opengl32)
target_link_libraries(main $ENV{GLEW_ROOT}/lib/Release/Win32/glew32s.lib $ENV{GLUT_ROOT}/Release/glut32.lib opengl32)

if(WIN32)
	message("win32")
	file(COPY $ENV{GLEW_ROOT}/bin/Release/Win32/glew32.dll DESTINATION ${PROJECT_BINARY_DIR})
	file(COPY $ENV{GLUT_ROOT}/Release/glut32.dll DESTINATION ${PROJECT_BINARY_DIR})
endif()
