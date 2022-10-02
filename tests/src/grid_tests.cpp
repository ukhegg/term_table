//
// Created by ukhegg on 23.10.2020.
//

#include <catch2/catch.hpp>

#include <term_table/grid_t.hpp>

using namespace term_table;

namespace term_table::tests
{
    TEST_CASE("grid_t tests")
    {
        grid_t g;
        REQUIRE(g.rows_count() == 0);
        REQUIRE(g.columns_count() == 0);
    }
}
