if(CMAKE_GENERATOR STREQUAL "MinGW Makefiles")
	set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)
endif()
add_executable(main main.cpp)
