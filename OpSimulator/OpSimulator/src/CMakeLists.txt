
cmake_minimum_required (VERSION 3.8)
//project(OpSimulator VERSION 1.0)

//set(CMAKE_CXX_STANDARD 14)

//set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include})

add_executable (OpSimulator OpSimulator.cpp ${MY_INCLUDE_DIR}/OpSimulator.h)
target_include_directories(OpSimulator PUBLIC ${MY_INCLUDE_DIR})
