//
// Created by Zeliukin Nick on 13.09.22.
//

#include "term_table/internal/table_builder_t.hpp"
#include "term_table/internal/table_data_t.hpp"

#include <stdexcept>

namespace term_table::internal
{

    table_builder_t::table_data_ptr table_builder_t::get_result()
    {
        return std::make_shared<table_data_t>(this->rows_count_, this->columns_count_);
    }

    void table_builder_t::set_param(keywords::rows_count rows_count)
    {
        if (rows_count.value == 0) {
            throw std::invalid_argument("rows count cannot be 0");
        }

        this->rows_count_ = rows_count.value;
    }

    void table_builder_t::set_param(keywords::columns_count columns_count)
    {
        if (columns_count.value == 0) {
            throw std::invalid_argument("columns count cannot be 0");
        }
        this->columns_count_ = columns_count.value;
    }
}