//
// Created by Zeliukin Nick on 13.09.22.
//

#include "term_table/index_2d.hpp"

namespace term_table
{

    index_2d::index_2d()
    {
    }

    index_2d::index_2d(row_index_t row, column_index_t column)
            : row_(row.value()), column_(column.value())
    {
    }

    row_index_t index_2d::row() const
    {
        return {this->row_};
    }

    column_index_t index_2d::column() const
    {
        return {this->column_};
    }

    bool index_2d::operator==(const index_2d &rhs) const
    {
        return row_ == rhs.row_ &&
               column_ == rhs.column_;
    }

    bool index_2d::operator!=(const index_2d &rhs) const
    {
        return !(rhs == *this);
    }

    bool index_2d::operator<(const index_2d &rhs) const
    {
        if (row_ < rhs.row_)
            return true;
        if (rhs.row_ < row_)
            return false;
        return column_ < rhs.column_;
    }

    bool index_2d::operator>(const index_2d &rhs) const
    {
        return rhs < *this;
    }

    bool index_2d::operator<=(const index_2d &rhs) const
    {
        return !(rhs < *this);
    }

    bool index_2d::operator>=(const index_2d &rhs) const
    {
        return !(*this < rhs);
    }
}
