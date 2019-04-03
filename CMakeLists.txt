cmake_minimum_required(VERSION 3.10)
project(todolist LANGUAGES CXX)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

#find_package(doctest REQUIRED)

add_library(entry entry.cc)
add_library(table table.cc)
target_include_directories(entry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#add_executable(main_test test.cc)
add_executable(main main.cc)

#target_link_libraries(main_test PRIVATE list doctest::doctest)
target_link_libraries(main PRIVATE entry table)

#add_test(todo_test main_test)
