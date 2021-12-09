# @file chapter4/utils/CMakeLists.txt
# @author HinsShum hinsshum@qq.com
# @date 2021/11/30 13:09:21
# @encoding utf-8
# @brief Here's the first line of every CMakeLists.txt,
#        which is the required name of the file CMake looks for:
cmake_minimum_required(VERSION 3.1)

file(GLOB C_FILES "*.c")
file(GLOB CXX_FILES "*.cpp")

# get sub directory
file(GLOB_RECURSE CMAKELISTS "CMakeLists.txt")
dirname(CMAKELISTS CMAKELISTS_DIRS)
filter_out(CMAKE_CURRENT_SOURCE_DIR CMAKELISTS_DIRS CMAKELISTS_DIRS)
foreach(CMAKELISTS_SUB_DIR ${CMAKELISTS_DIRS})
    add_subdirectory(${CMAKELISTS_DIRS})
endforeach(CMAKELISTS_SUB_DIR)

# set global variables
set(C_SOURCE_FILES ${C_SOURCE_FILES} ${C_FILES} PARENT_SCOPE)
set(CXX_SOURCE_FILES ${CXX_SOURCE_FILES} ${CXX_FILES} PARENT_SCOPE)
set(G_SOURCE_INCLUDE_DIRS ${G_SOURCE_INCLUDE_DIRS} "${CMAKE_CURRENT_SOURCE_DIR}/include" PARENT_SCOPE)