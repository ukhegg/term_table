//
// Created by Zeliukin Nick on 12.09.22.
//

#pragma once

#include "term_table/row_index_t.hpp"
#include "term_table/column_index_t.hpp"

#include <memory>
#include <string>

namespace term_table
{
    namespace internal
    {
        class cell_data_t;
    }

    class table_cell_t
    {
    public:
        using cell_data_ptr = std::shared_ptr<internal::cell_data_t>;

        table_cell_t() = default;

        table_cell_t(row_index_t row, column_index_t column, cell_data_ptr cell_data);

        void set_data(std::string data);

        std::string const& data();
    private:
        row_index_t row_;
        column_index_t column_;
        cell_data_ptr cell_data_;
    };
}

