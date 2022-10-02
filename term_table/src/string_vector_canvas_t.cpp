//
// Created by Zeliukin Nick on 13.09.22.
//

#include "term_table/string_vector_canvas_t.hpp"

namespace term_table
{
    void string_vector_canvas_t::put(row_index_t row, column_index_t column, char symbol)
    {
        if (column.value() >= this->line_width_) {
            this->line_width_ = column.value() + 1;
            for (auto line: this->lines_) {
                line.resize(this->line_width_, ' ');
            }
        }

        while (this->lines_.size() <= row.value()) {
            this->lines_.emplace_back(this->line_width_, ' ');
        }

        this->lines_.at(row.value()).at(column.value()) = symbol;
    }

    const std::vector<std::string> &string_vector_canvas_t::lines() const
    {
        return lines_;
    }
}