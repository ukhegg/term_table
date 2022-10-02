//
// Created by Zeliukin Nick on 12.09.22.
//

#include "term_table/table_t.hpp"
#include "term_table/internal/table_data_t.hpp"
#include <stdexcept>

namespace term_table
{
    table_t::table_t()
    {
        internal::table_builder_t tb;
        tb.set_param(keywords::rows_count::equals = 1);
        tb.set_param(keywords::columns_count::equals = 1);
        this->data_ = tb.get_result();
    }

    table_t::table_t(table_t::table_data_ptr data)
            : data_(std::move(data))
    {
    }

    table_cell_t table_t::get_cell(row_index_t r_index, column_index_t c_index) const
    {
        return this->data_->cells().at(r_index, c_index);
    }

    size_t table_t::rows_count() const
    {
        return this->data_->rows_count();
    }

    size_t table_t::columns_count() const
    {
        return this->data_->columns_count();
    }

    void table_t::draw(i_canvas &canvas)
    {
        this->data_->draw(canvas);
    }


}
