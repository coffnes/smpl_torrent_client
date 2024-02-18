cmake_minimum_required(VERSION 3.16)
project(SmplTorrentClient)

set(CMAKE_CXX_STANDART 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(lib)
include_directories(include)

add_library(cxxopts STATIC lib/cxxopts/cxxopts.hpp)
set_target_properties(cxxopts PROPERTIES LINKER_LANGUAGE CXX)

add_executable(SmplTorrentClient src/main.cpp)

#add test
enable_testing()
add_subdirectory(test)
