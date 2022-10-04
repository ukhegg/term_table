cmake_minimum_required(VERSION 3.17)
project(term_table_lib)

set(CMAKE_CXX_STANDARD 17)

FetchContent_MakeAvailable(simplex_solver)

add_definitions(-DTERM_TABLE_DLL_EXPORTS)
if (BUILD_SHARED_LIBS)
    add_definitions(-DTERM_TABLE_DLL)
endif ()

set(SOURCE_FILES
        include/term_table/term_table_api.hpp
        include/term_table/grid_t.hpp
        src/grid_t.cpp
        src/table_t.cpp
        include/term_table/table_t.hpp
        src/table_cell_t.cpp
        include/term_table/table_cell_t.hpp
        src/row_index_t.cpp
        include/term_table/row_index_t.hpp
        src/column_index_t.cpp
        include/term_table/column_index_t.hpp
        include/term_table/integer_index_t.hpp
        src/internal/cells_collection_t.cpp
        include/term_table/internal/cells_collection_t.hpp
        src/internal/cell_data_t.cpp
        include/term_table/internal/cell_data_t.hpp
        include/term_table/keywords/internal/tagged_value_t.hpp
        include/term_table/keywords/table_keywords.hpp
        src/internal/table_builder_t.cpp
        include/term_table/internal/table_builder_t.hpp
        src/internal/table_data_t.cpp
        include/term_table/internal/table_data_t.hpp
        include/term_table/i_canvas.hpp
        src/string_vector_canvas_t.cpp
        include/term_table/string_vector_canvas_t.hpp
        src/index_2d.cpp
        include/term_table/index_2d.hpp
        src/visuals/label_t.cpp
        include/term_table/visuals/label_t.hpp
        include/term_table/i_visual.hpp
        include/term_table/i_canvas_area.hpp src/visuals/horizontal_border_t.cpp include/term_table/visuals/horizontal_border_t.hpp)


source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${SOURCE_FILES})
add_library(term_table ${SOURCE_FILES})

target_include_directories(term_table PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(term_table)