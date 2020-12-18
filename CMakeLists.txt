# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (myDB)
# 头文件目录
include_directories(.)
# 源文件目录
aux_source_directory(. DIR_SRCS)
# 指定生成目标
add_executable(test ${DIR_SRCS})
# 链接库
target_link_libraries(test pthread)
