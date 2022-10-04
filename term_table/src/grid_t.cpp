//
// Created by ukhegg on 23.10.2020.
//

#include "term_table/grid_t.hpp"
#include "term_table/visuals/label_t.hpp"
#include <stdexcept>

namespace term_table {
    grid_t::grid_t() = default;

    grid_t::grid_t(size_t rows_count, size_t columns_count)
            : rows_count_(rows_count),
              columns_count_(columns_count) {
        this->rows_info_.resize(rows_count);
        this->columns_info_.resize(columns_count);

        for (row_index_t row = 0; row < rows_count; ++row) {
            for (column_index_t column = 0; columns_count < columns_count; ++column) {
                auto &grid_cell = this->cells_[index_2d{row, column}];
            }
        }
    }

    size_t grid_t::rows_count() const {
        return this->rows_count_;
    }

    size_t grid_t::columns_count() const {
        return this->columns_count_;
    }

    grid_t::visual_ptr grid_t::get_content(index_2d index) {
        return this->cells_.at(index).content;
    }

    void grid_t::set_content(index_2d index, grid_t::visual_ptr visual) {
        this->cells_[index].content = visual;
    }

    void grid_t::set_text(index_2d index, std::string text) {
        this->set_content(index, std::make_shared<visuals::label_t>(std::move(text)));
    }

    size_t grid_t::row_min_height(row_index_t row) const {
        return this->rows_info_.at(row.index()).min_height;
    }

    size_t grid_t::column_min_width(column_index_t column) const {
        return this->columns_info_.at(column.index()).min_width;
    }

    void grid_t::set_column_min_width(column_index_t column, size_t width) {
        column_info_t &column_info = this->columns_info_.at(column.index());
        if (column_info.max_width < width) {
            throw std::invalid_argument("column max_width < min_width");
        }
        column_info.min_width = width;
    }

    void grid_t::set_column_max_width(column_index_t column, size_t width) {
        column_info_t &column_info = this->columns_info_.at(column.index());
        if (column_info.min_width > width) {
            throw std::invalid_argument("column min_width > max_width");
        }
        column_info.max_width = width;
    }

    void grid_t::set_row_min_height(row_index_t row, size_t height) {
        row_info_t &row_info = this->rows_info_.at(row.index());
        if (row_info.max_height < height) {
            throw std::invalid_argument("row max_height < min_height");
        }

        row_info.min_height = height;
    }

    void grid_t::set_row_max_height(row_index_t row, size_t height) {
        row_info_t &row_info = this->rows_info_.at(row.index());
        if (row_info.min_height > height) {
            throw std::invalid_argument("row min_height > max_height");
        }

        row_info.max_height = height;
    }
}
