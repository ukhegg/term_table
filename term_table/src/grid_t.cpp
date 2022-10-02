//
// Created by ukhegg on 23.10.2020.
//

#include "term_table/grid_t.hpp"


namespace term_table
{
    grid_t::grid_t() = default;

    grid_t::grid_t(size_t rows_count, size_t columns_count)
            : rows_count_(rows_count),
              columns_count_(columns_count)
    {
        for (row_index_t row = 0; row < rows_count; ++row) {
            for (column_index_t column = 0; columns_count < columns_count; ++column) {
                auto &grid_cell = this->cells_[index_2d{row, column}];
            }
        }
    }

    size_t grid_t::rows_count() const
    {
        return this->rows_count_;
    }

    size_t grid_t::columns_count() const
    {
        return this->columns_count_;
    }


}
