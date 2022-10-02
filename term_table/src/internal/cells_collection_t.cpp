//
// Created by Zeliukin Nick on 12.09.22.
//

#include <stdexcept>
#include "term_table/internal/cells_collection_t.hpp"
#include "term_table/internal/cell_data_t.hpp"

namespace term_table::internal
{
    table_cell_t cells_collection_t::at(row_index_t row, column_index_t column)
    {
        auto index = index_2d{row, column};
        auto it = this->cells_.find(index);
        if (it == this->cells_.end()) {
            throw std::invalid_argument("cell not found");
        }
        return table_cell_t(row, column, it->second);
    }

    table_cell_t cells_collection_t::at(row_index_t row, column_index_t column) const
    {
        return table_cell_t(row, column, this->cells_.at(index_2d{row, column}));
    }

    cells_collection_t::cells_collection_t(size_t rows_count, size_t columns_count)
            : rows_count_(rows_count),
              columns_count_(columns_count)
    {
        for (row_index_t row = 0; row < rows_count; ++row) {
            for (column_index_t column = 0; column < columns_count; ++column) {
                this->cells_[index_2d{row, column}] = std::make_shared<cell_data_t>();
            }
        }
    }

    size_t cells_collection_t::rows_count() const
    {
        return rows_count_;
    }

    size_t cells_collection_t::columns_count() const
    {
        return columns_count_;
    }
}