//
// Created by Zeliukin Nick on 02.10.22.
//
#include <term_table/string_vector_canvas_t.hpp>
#include <catch2/catch.hpp>

namespace term_table::tests
{
    TEST_CASE("string_vector_canvas_t tests")
    {
        string_vector_canvas_t canvas;
        std::vector<std::string> expected_lines;

        SECTION("empty canvas test")
        {
            auto lines = canvas.lines();
            REQUIRE(lines.empty());
        }

        SECTION("single symbol tests")
        {
            canvas.put(row_index_t{1}, column_index_t{3}, 's');
            expected_lines = {"s"};
            REQUIRE(canvas.lines() == expected_lines);
        }

        SECTION("more complex test")
        {
            canvas.put(row_index_t{1}, column_index_t{3}, 'h');
            canvas.put(row_index_t{1}, column_index_t{4}, 'e');
            canvas.put(row_index_t{1}, column_index_t{5}, 'l');
            canvas.put(row_index_t{1}, column_index_t{6}, 'l');
            canvas.put(row_index_t{1}, column_index_t{7}, 'o');

            canvas.put(row_index_t{3}, column_index_t{5}, 'w');
            canvas.put(row_index_t{3}, column_index_t{6}, 'o');
            canvas.put(row_index_t{3}, column_index_t{7}, 'r');
            canvas.put(row_index_t{3}, column_index_t{8}, 'l');
            canvas.put(row_index_t{3}, column_index_t{9}, 'd');

            expected_lines = {"hello  ",
                              "       ",
                              "  world"};
            REQUIRE(canvas.lines() == expected_lines);
        }
    }
}