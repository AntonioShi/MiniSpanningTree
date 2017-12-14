cmake_minimum_required(VERSION 3.8)
project(MiniSpanningTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Prim.h AdjMGraph.h AdjMGraphCreate.h)
add_executable(MiniSpanningTree ${SOURCE_FILES} Prim.h)