cmake_minimum_required(VERSION 3.16)
project(SmplTorrentClient)

set(CMAKE_CXX_STANDART 14)
include_directories(lib)
include_directories(include)

add_executable(SmplTorrentClient src/main.cpp)