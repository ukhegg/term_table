cmake_minimum_required(VERSION 3.17)
project(term_table_tests)

set(CMAKE_CXX_STANDARD 17)



set(SOURCE_FILES
        src/main.cpp
        src/grid_tests.cpp)

SOURCE_GROUP(TREE ${PROJECT_SOURCE_DIR} FILES ${SOURCE_FILES})

add_executable(tests ${SOURCE_FILES})
target_include_directories(tests PRIVATE ${term_table_SOURCE_DIR}/include)
target_link_libraries(tests term_table ${CONAN_LIBS})