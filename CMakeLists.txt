cmake_minimum_required(VERSION 3.28)
project(ergasiadomes)

set(CMAKE_CXX_STANDARD 17)

add_executable(ergasiadomes main.cpp
        MinHeap.cpp
        MinHeap.h
        MaxHeap.cpp
        MaxHeap.h
        Hashtable.cpp
        Hashtable.h
)
