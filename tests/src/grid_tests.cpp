//
// Created by ukhegg on 23.10.2020.
//

#include <catch2/catch.hpp>

#include <term_table/grid_t.hpp>
#include <term_table/visuals/label_t.hpp>


using namespace term_table;

namespace term_table::tests {
    TEST_CASE("grid_t tests")
    {
        SECTION("default constructed grid is 0x0 size")
        {
            grid_t g;
            REQUIRE(g.rows_count() == 0);
            REQUIRE(g.columns_count() == 0);
        }

        SECTION("can set some data in cell")
        {
            std::string text = "hello\nworld\n!";
            grid_t g(1, 1);

            auto cell_index = index_2d{row_index_t{0}, column_index_t{0}};
            g.set_text(cell_index, text);

            auto content = g.get_content(cell_index);
            auto label_content = std::dynamic_pointer_cast<visuals::label_t>(content);
            REQUIRE(label_content != nullptr);
            REQUIRE(label_content->text() == text);
        }
    }
}
