cmake_minimum_required(VERSION 3.19)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        DSA
        BasicAlgorithms/kadane.cpp
        BasicAlgorithms/graphs/dfs.cpp
        BasicAlgorithms/graphs/bfs.cpp
)