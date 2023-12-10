cmake_minimum_required(VERSION 3.5)

project(SingleLinkedList)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp node.cpp linked-list.cpp)

target_include_directories(main PRIVATE include)

# Add input.txt
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt
  ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
