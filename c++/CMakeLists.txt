project(c++)
cmake_minimum_required(VERSION 2.8.0)
add_compile_options(-std=c++11)

# SET(CMAKE_C_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe")
# SET(CMAKE_CXX_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe")

add_executable(11 11.cpp)

# cmake -G "Unix Makefiles" ../