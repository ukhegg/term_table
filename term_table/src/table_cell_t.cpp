//
// Created by Zeliukin Nick on 12.09.22.
//

#include <memory>
#include "term_table/table_cell_t.hpp"
#include "term_table/internal/cell_data_t.hpp"
namespace term_table
{

    table_cell_t::table_cell_t(row_index_t row, column_index_t column,
                               cell_data_ptr cell_data)
            : row_(row), column_(column),
              cell_data_(std::move(cell_data))
    {
    }

    void table_cell_t::set_data(std::string data)
    {
        this->cell_data_->set_data(std::move(data));
    }

    std::string const &table_cell_t::data()
    {
        return this->cell_data_->data();
    }
}