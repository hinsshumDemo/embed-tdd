# @file test/mock/CMakeLists.txt
# @author HinsShum hinsshum@qq.com
# @date 2021/12/09 09:10:21
# @encoding utf-8
# @brief Here's the first line of every CMakeLists.txt,
#        which is the required name of the file CMake looks for:
cmake_minimum_required(VERSION 3.1)

# add all source code file to be compiled
file(GLOB SUB_C_FILES "*.c")
file(GLOB SUB_CXX_FILES "*.cpp")

# filter out source code file not to be compiled
set(SUB_C_OUT "")
set(SUB_CXX_OUT "")
filter_out(SUB_C_OUT SUB_C_FILES SUB_C_FILES)
filter_out(SUB_CXX_OUT SUB_CXX_FILES SUB_CXX_FILES)

# set variable
set(C_FILES ${C_FILES} ${SUB_C_FILES} PARENT_SCOPE)
set(CXX_FILES ${CXX_FILES} ${SUB_CXX_FILES} PARENT_SCOPE)
set(G_SOURCE_INCLUDE_DIRS ${G_SOURCE_INCLUDE_DIRS} "${CMAKE_CURRENT_SOURCE_DIR}/include" PARENT_SCOPE)