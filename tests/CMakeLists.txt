cmake_minimum_required(VERSION 3.17)
project(term_table_tests)

set(CMAKE_CXX_STANDARD 17)

find_package(Catch2 REQUIRED)

FetchContent_MakeAvailable(fakeit)

set(SOURCE_FILES
        src/main.cpp
        src/grid_tests.cpp src/term_table_tests.cpp src/string_vector_canvas_tests.cpp)

SOURCE_GROUP(TREE ${PROJECT_SOURCE_DIR} FILES ${SOURCE_FILES})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${term_table_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} term_table Catch2::Catch2WithMain )