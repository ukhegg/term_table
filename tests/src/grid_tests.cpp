//
// Created by ukhegg on 23.10.2020.
//

#include <catch2/catch.hpp>

#include <term_table/grid.hpp>
using namespace term_table;


TEST_CASE("grid tests", "default created grid has size of 0x0")
{
	grid g;
	REQUIRE(g.height() == 0);
	REQUIRE(g.width() == 0);
}