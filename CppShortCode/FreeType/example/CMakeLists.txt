include_directories(E:/freetype2/include/win32)

add_executable(example example1.c)
target_link_libraries(example E:/freetype2/prebuilt/win32/freetype250.lib)
