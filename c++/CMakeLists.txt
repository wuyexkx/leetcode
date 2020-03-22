project(c++)
cmake_minimum_required(VERSION 2.8.0)
add_compile_options(-std=c++11)

# SET(CMAKE_C_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe")
# SET(CMAKE_CXX_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe")
# SET(CMAKE_C_COMPILER "C:/My_Software/mingw-w64/mingw64/bin/gcc.exe")
# SET(CMAKE_CXX_COMPILER "C:/My_Software/mingw-w64/mingw64/bin/g++.exe")

add_executable(设计哈希集合 设计哈希集合.cpp)

# 编译时可能需要
# cmake -G "Unix Makefiles" ../

# 在编译参数中增加以下两条指令：
# -fexec-charset=gbk
# -finput-charset=gbk
# 原因简单分析：
#     Windows(中文)默认的字符集是Windows-936(GBK)，
#     而GCC编译器默认编译的时候是按照UTF-8解析的，
#     当未指定字符集时一律当作UTF-8进行处理，于是造成乱码