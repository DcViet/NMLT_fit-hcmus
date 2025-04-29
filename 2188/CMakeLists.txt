cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include headers
include_directories(
    include
    include/Book
    include/Borrow
    include/Reader
    include/Statistic
)

# Find all .cpp files recursively inside src/
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Define executable
add_executable(LibraryManagementSystem ${SOURCES})
