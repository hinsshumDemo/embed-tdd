# @file chapter1/test/CMakeLists.txt
# @author HinsShum hinsshum@qq.com
# @date 2021/11/29 14:08:12
# @encoding utf-8
# @brief Here's the first line of every CMakeLists.txt,
#        which is the required name of the file CMake looks for:
cmake_minimum_required(VERSION 3.1)

set(C_SOURCE_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")

# add c, cpp files to compile
file(GLOB C_FILES "*.c")
file(GLOB CXX_FILES "*.cpp")

# add subdirectory to search c or cxx files
file(GLOB_RECURSE CPPUTEST_CMAKELISTS "CMakeLists.txt")
dirname(CPPUTEST_CMAKELISTS CPPUTEST_CMAKELISTS_DIRS)
filter_out(CMAKE_CURRENT_SOURCE_DIR CPPUTEST_CMAKELISTS_DIRS CPPUTEST_CMAKELISTS_DIRS)
foreach(CPPUTEST_SUB_DIR ${CPPUTEST_CMAKELISTS_DIRS})
    add_subdirectory(${CPPUTEST_SUB_DIR})
endforeach(CPPUTEST_SUB_DIR)

set(C_SOURCE_FILES ${C_SOURCE_FILES} ${C_FILES} PARENT_SCOPE)
set(CXX_SOURCE_FILES ${CXX_SOURCE_FILES} ${CXX_FILES} PARENT_SCOPE)
set(G_SOURCE_INCLUDE_DIRS ${G_SOURCE_INCLUDE_DIRS} ${C_SOURCE_INCLUDE_DIRS} PARENT_SCOPE)