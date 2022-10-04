//
// Created by Zeliukin Nick on 13.09.22.
//

#pragma once

#include "term_table/i_canvas_area.hpp"
#include "term_table/index_2d.hpp"

#include <vector>
#include <string>
#include <map>

namespace term_table
{
    class string_vector_canvas_t : public i_canvas_area
    {
    public:
        void put(row_index_t row, column_index_t column, char symbol) override;

        size_t width() override;

        size_t height() override;

        std::vector<std::string> lines() const;
    private:
        row_index_t min_row_{0};
        row_index_t max_row_{0};
        column_index_t min_column_{0};
        column_index_t max_column_{0};
        std::map<index_2d, char> symbols_;

        void update_boundaries(row_index_t row, column_index_t column);
    };
}
