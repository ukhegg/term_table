//
// Created by Zeliukin Nick on 13.09.22.
//

#pragma once

#include "term_table/row_index_t.hpp"
#include "term_table/column_index_t.hpp"

namespace term_table
{
    class index_2d
    {
    public:
        index_2d();

        index_2d(row_index_t row, column_index_t column);

        row_index_t row() const;

        column_index_t column() const;

        bool operator==(const index_2d &rhs) const;

        bool operator!=(const index_2d &rhs) const;

        bool operator<(const index_2d &rhs) const;

        bool operator>(const index_2d &rhs) const;

        bool operator<=(const index_2d &rhs) const;

        bool operator>=(const index_2d &rhs) const;

    private:
        size_t row_{0};
        size_t column_{0};
    };
}


