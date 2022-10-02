//
// Created by Zeliukin Nick on 13.09.22.
//

#include "term_table/internal/table_data_t.hpp"

namespace term_table::internal
{
    class horizontal_border_t : public i_visual
    {
    public:
        size_t min_width() override
        {
            return 0;
        }

        size_t min_height() override
        {
            return 1;
        }

    private:
        char fill_{'-'};
    };

    table_data_t::table_data_t(size_t rows_count, size_t columns_count)
            : cells_(rows_count, columns_count)
    {
        this->grid_ = std::make_shared<grid_t>(rows_count * 2 + 1,
                                               columns_count * 2 + 1);

        for (row_index_t border_row = 0; border_row < this->grid_->rows_count(); border_row += 2) {
            for (column_index_t column = 0; column < this->grid_->columns_count(); ++column) {
                index_2d index{border_row, column};
                this->grid_->set_visual(index_2d{border_row, column}, std::make_shared<horizontal_border_t>());
            }
        }

        for (column_index_t column = 0; column < this->grid_->columns_count(); ++column) {

        }

    }

    size_t table_data_t::rows_count() const
    {
        return this->cells_.rows_count();
    }

    size_t table_data_t::columns_count() const
    {
        return this->cells_.columns_count();
    }

    cells_collection_t &table_data_t::cells()
    {
        return this->cells_;
    }

    cells_collection_t const &table_data_t::cells() const
    {
        return this->cells_;
    }

    void table_data_t::draw(i_canvas &canvas) const
    {

    }
}