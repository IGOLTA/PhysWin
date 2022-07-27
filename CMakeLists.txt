cmake_minimum_required(VERSION 3.23)
project(PhysWin)

set(CMAKE_CXX_STANDARD 20)


add_executable(PhysWin main.cpp)

#For linux
target_link_libraries(PhysWin SDL2)
target_include_directories(PhysWin PRIVATE /usr/include)

#For windows
#target_include_directories(PhysWin PRIVATE ${CMAKE_SOURCE_DIR}/SDL2-2.0.22/x86_64-w64-mingw32/include)
#target_link_libraries(PhysWin ${CMAKE_SOURCE_DIR}/SDL2-2.0.22/x86_64-w64-mingw32/lib/libSDL2main.a ${CMAKE_SOURCE_DIR}/SDL2-2.0.22/x86_64-w64-mingw32/lib/libSDL2.dll.a)
