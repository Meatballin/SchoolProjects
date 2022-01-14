cmake_minimum_required(VERSION 3.20)
project(BinSearchTree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
add_executable(BinSearchTree BinSearchTree.cpp BinSearchTree.hpp main.cpp TreeNode.hpp)
