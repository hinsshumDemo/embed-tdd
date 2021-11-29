# @file chapter1/tools/linux.cmake
# @author HinsShum hinsshum@qq.com
# @date 2021/11/29 14:18:10
# @encoding utf-8
# @brief Here's the first line of every linux.cmake,
#        which is the required name of the file CMake looks for:
cmake_minimum_required(VERSION 3.1)

# Set workspace folder
set(WORKSPACE_FOLDER ${PROJECT_SOURCE_DIR})

add_subdirectory("${WORKSPACE_FOLDER}/src")