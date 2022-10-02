cmake_minimum_required(VERSION 3.17)
project(term_table)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(fakeit
        GIT_REPOSITORY https://github.com/eranpeer/FakeIt.git
        GIT_TAG 2.3.0)
FetchContent_Declare(simplex_solver
        GIT_REPOSITORY https://github.com/ukhegg/simpex_solver.git
        GIT_TAG v0.1.0)


add_subdirectory(term_table)
add_subdirectory(tests)