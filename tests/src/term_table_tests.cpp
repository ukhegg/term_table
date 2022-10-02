//
// Created by Zeliukin Nick on 12.09.22.
//
#include <catch2/catch.hpp>
#include <term_table/table_t.hpp>

#include <term_table/string_vector_canvas_t.hpp>

namespace term_table::tests
{
    TEST_CASE("table_t tests")
    {
        SECTION("data set/get tests") {
            SECTION("default constructed table is 1x1 size") {
                table_t table;
                REQUIRE(table.rows_count() == 1);
                REQUIRE(table.columns_count() == 1);

                auto cell = table.get_cell(row_index_t{0}, column_index_t{0});
            }

            SECTION("accessing non-existing cell throws exception") {
                table_t table;

                REQUIRE_THROWS_AS(table.get_cell(row_index_t{1}, column_index_t{1}), std::invalid_argument);
            }

            SECTION("non-trivial table size") {
                table_t table(keywords::rows_count::equals = 2,
                              keywords::columns_count::equals = 3);

                REQUIRE(table.rows_count() == 2);
                REQUIRE(table.columns_count() == 3);

                auto cell_0_0 = table.get_cell(row_index_t{0}, column_index_t{0});
                auto cell_0_1 = table.get_cell(row_index_t{0}, column_index_t{1});
                auto cell_0_2 = table.get_cell(row_index_t{0}, column_index_t{2});
                auto cell_1_0 = table.get_cell(row_index_t{1}, column_index_t{0});
                auto cell_1_1 = table.get_cell(row_index_t{1}, column_index_t{1});
                auto cell_1_2 = table.get_cell(row_index_t{1}, column_index_t{2});
            }

            SECTION("can put data into table cell") {
                table_t table;

                table.get_cell(row_index_t{0}, column_index_t{0}).set_data("hello world");

                REQUIRE(table.get_cell(row_index_t{0}, column_index_t{0}).data() == "hello world");
            }

            SECTION("can print simple table") {
                table_t table(keywords::rows_count::equals = 2,
                              keywords::columns_count::equals = 2);

                table.get_cell(row_index_t{0}, column_index_t{0}).set_data("hello");
                table.get_cell(row_index_t{0}, column_index_t{1}).set_data("world");
                table.get_cell(row_index_t{1}, column_index_t{0}).set_data("motherlover");
                table.get_cell(row_index_t{1}, column_index_t{1}).set_data("!");

                string_vector_canvas_t canvas;
                table.draw(canvas);

                std::vector<std::string> expected = {
                        "-------------------",
                        "|hello      |world|",
                        "-------------------",
                        "|motherlover|!    |",
                        "-------------------"
                };
                REQUIRE(canvas.lines() == expected);
            }
        }
    }
}