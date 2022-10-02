//
// Created by Zeliukin Nick on 13.09.22.
//

#include "term_table/string_vector_canvas_t.hpp"

namespace term_table
{
    void string_vector_canvas_t::put(row_index_t row, column_index_t column, char symbol)
    {
        this->update_boundaries(row, column);
        this->symbols_[index_2d{row, column}] = symbol;
    }

    std::vector<std::string> string_vector_canvas_t::lines() const
    {
        if (this->symbols_.empty()) return {};

        auto width = this->max_column_.value() - this->min_column_.value() + 1;
        auto height = this->max_row_.value() - this->min_row_.value() + 1;

        std::vector<std::string> result(height);
        for (auto &line: result) {
            line.resize(width, ' ');
        }

        for (auto [index, symbol]: this->symbols_) {
            result.at(index.row().value() - this->min_row_.value())
                    .at(index.column().value() - this->min_column_.value()) = symbol;
        }
        return result;
    }

    void string_vector_canvas_t::update_boundaries(row_index_t row, column_index_t column)
    {
        if (this->symbols_.empty()) {
            this->min_row_ = this->max_row_ = row;
            this->min_column_ = this->max_column_ = column;
        } else {
            this->min_row_ = std::min(row, this->min_row_);
            this->max_row_ = std::max(row, this->max_row_);
            this->min_column_ = std::min(column, this->min_column_);
            this->max_column_ = std::max(column, this->max_column_);
        }
    }
}