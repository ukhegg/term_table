//
// Created by Zeliukin Nick on 12.09.22.
//

#include "term_table/internal/cell_data_t.hpp"

namespace term_table::internal
{

    const std::string &cell_data_t::data() const
    {
        return data_;
    }

    void cell_data_t::set_data(std::string data)
    {
        data_ = std::move(data);
    }
}