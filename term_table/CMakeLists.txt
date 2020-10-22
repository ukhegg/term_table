cmake_minimum_required(VERSION 3.17)
project(term_table_lib)

set(CMAKE_CXX_STANDARD 17)


add_definitions(-DTERM_TABLE_DLL_EXPORTS)
if(BUILD_SHARED_LIBS)
    add_definitions(-DTERM_TABLE_DLL)
endif()

if (MSVC)
    #add_definitions(/MP -DBOOST_SYSTEM_NO_DEPRECATED -D_WIN32_WINNT=0x0601)
    #add_definitions(/wd4251 /wd4275 /wd4005 /wd4503 /wd4290 -D_SCL_SECURE_NO_WARNINGS)
else ()
    message("not ready for non-msvc compilation")
endif ()

set(HEADER_FILES
        include/term_table/term_table_api.hpp
        include/term_table/grid.hpp
        )

set(SOURCE_FILES
        src/grid.cpp)


source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${HEADER_FILES} ${SOURCE_FILES} )
add_library(term_table ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(term_table PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(term_table ${CONAN_LIBS})