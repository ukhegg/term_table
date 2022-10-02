//
// Created by Zeliukin Nick on 13.09.22.
//

#pragma once

#include "term_table/row_index_t.hpp"
#include "term_table/column_index_t.hpp"

namespace term_table
{
    class i_canvas
    {
    public:
        virtual ~i_canvas() = default;

        virtual void put(row_index_t row, column_index_t column, char symbol) = 0;
    };
}

