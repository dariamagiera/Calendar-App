cmake_minimum_required(VERSION 3.13)
project(Calendar)

set(CMAKE_CXX_STANDARD 14)

add_executable(Calendar main.cpp Calendar.cpp Calendar.h Day.h Day.cpp Event.h Event.cpp)