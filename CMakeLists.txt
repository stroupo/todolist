cmake_minimum_required(VERSION 3.10)
project(todolist LANGUAGES CXX)
enable_testing()

add_subdirectory(tests)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_library(table entry.cc table.cc)

target_include_directories(table PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(table PUBLIC cxx_std_17)

add_executable(main mainqt.cc window.cc window.h)
set_target_properties(main PROPERTIES AUTOMOC TRUE)
target_link_libraries(main PRIVATE Qt5::Widgets table)
