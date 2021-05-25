cmake_minimum_required(VERSION 3.0)

project(SA_FSP)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(main_cmake main.cpp src/Machine.cpp src/Workpiece.cpp src/Simulate.cpp)