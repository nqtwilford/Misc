cmake_minimum_required(VERSION 2.8)

add_executable(KeyBuilder KeyBuilder.cpp)

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/keys.h
	COMMAND KeyBuilder
	DEPENDS KeyBuilder )

include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(SRCS TestUnorderedMap.cpp
		 ${CMAKE_CURRENT_BINARY_DIR}/keys.h)

add_executable(TestUnorderedMap ${SRCS})
target_link_libraries(TestUnorderedMap winmm.lib)
