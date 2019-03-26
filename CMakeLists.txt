cmake_minimum_required(VERSION 3.10)
project(todolist LANGUAGES CXX)
enable_testing()

#find_package(doctest REQUIRED)

add_library(list INTERFACE)
target_include_directories(list INTERFACE .)

#add_executable(main_test test.cc)
add_executable(main main.cc)

#target_link_libraries(main_test PRIVATE list doctest::doctest)
target_link_libraries(main PRIVATE list)

#add_test(todo_test main_test)
