//
// Created by Zeliukin Nick on 13.09.22.
//

#pragma once

#include "term_table/i_canvas.hpp"

#include <vector>
#include <string>

namespace term_table
{
    class string_vector_canvas_t : public i_canvas
    {
    public:
        void put(row_index_t row, column_index_t column, char symbol) override;

        const std::vector<std::string> &lines() const;
    private:
        size_t line_width_{0};
        std::vector<std::string> lines_;
    };
}
