cmake_minimum_required(VERSION 3.10)

find_package(doctest REQUIRED)

add_executable(todo_test todo_test.cc)

target_link_libraries(todo_test PRIVATE table)
add_test(todo_test todo_test)
