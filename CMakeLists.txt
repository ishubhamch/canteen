cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(main CXX)
#project(main)
#file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/*.cpp")
# get all *.cpp files recursively
#file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/*/*.cpp)
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
add_executable(mcanteen ${SRC_FILES})
