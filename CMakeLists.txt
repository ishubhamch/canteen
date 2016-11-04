cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(canteen CXX)

# get all *.cpp files recursively
#file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/*.cpp")
#file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
#include_directories ("${PROJECT_SOURCE_DIR}/class")
#add_subdirectory (class)
add_executable(canteen function.cpp class/Student.cpp class/Stud.cpp class/Item.cpp main.cpp)
