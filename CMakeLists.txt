cmake_minimum_required(VERSION 3.17)
project(term_table)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


add_subdirectory(term_table)
add_subdirectory(tests)