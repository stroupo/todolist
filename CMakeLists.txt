cmake_minimum_required(VERSION 3.10)
project(todolist LANGUAGES CXX)

add_library(list INTERFACE)
target_include_directories(list INTERFACE .)

add_executable(main main.cc)
