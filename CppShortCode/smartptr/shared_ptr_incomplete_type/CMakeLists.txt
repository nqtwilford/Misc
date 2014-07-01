cmake_minimum_required(VERSION 2.8)

find_package(Boost REQUIRED)
if(Boost_FOUND)
	message(${Boost_INCLUDE_DIRS})
	include_directories(${Boost_INCLUDE_DIRS})
endif()

message(${CMAKE_CXX_FLAGS})

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} " /WX")

message(${CMAKE_CXX_FLAGS})

set(SRC main.cpp A.h A.cpp B.h B.cpp C.h C.cpp)

add_executable(main ${SRC})
