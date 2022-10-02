//
// Created by Zeliukin Nick on 12.09.22.
//

#pragma once

#include "term_table/row_index_t.hpp"
#include "term_table/column_index_t.hpp"
#include "term_table/table_cell_t.hpp"
#include "term_table/index_2d.hpp"

#include <map>
#include <memory>

namespace term_table::internal
{
        class cell_data_t;

    class cells_collection_t
    {
    public:
        cells_collection_t() = default;

        cells_collection_t(size_t rows_count, size_t columns_count);

        size_t rows_count() const;

        size_t columns_count() const;

        table_cell_t at(row_index_t row, column_index_t column);

        table_cell_t at(row_index_t row, column_index_t column) const;


    private:
        using cell_data_ptr = std::shared_ptr<internal::cell_data_t>;

        size_t rows_count_{0};
        size_t columns_count_{0};
        std::map<index_2d, cell_data_ptr> cells_;
    };
}


