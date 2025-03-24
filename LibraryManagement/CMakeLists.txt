cmake_minimum_required(VERSION 3.10)
project(LibraryManagement)

set(CMAKE_CXX_STANDARD 11)

include_directories(include/core include/entities include/services include/utils)

file(GLOB SOURCES "src/core/*.cpp" "src/entities/*.cpp" "src/services/*.cpp" "src/utils/*.cpp" "src/main.cpp")

add_executable(library ${SOURCES})
