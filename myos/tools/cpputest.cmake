# @file chapter1/tools/cpputest.cmake
# @author HinsShum hinsshum@qq.com
# @date 2021/11/29 14:01:52
# @encoding utf-8
# @brief Here's the first line of every cpputest.cmake,
#        which is the required name of the file CMake looks for:
cmake_minimum_required(VERSION 3.1)

# Set workspace folder
set(WORKSPACE_FOLDER ${PROJECT_SOURCE_DIR})

# Set cpputest library
set(C_SOURCE_LIBS ${C_SOURCE_LIBS} "CppUTest" "CppUTestExt" "pthread")

add_subdirectory("${WORKSPACE_FOLDER}/test")