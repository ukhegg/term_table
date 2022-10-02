//
// Created by Zeliukin Nick on 13.09.22.
//

#pragma once

#include <cstddef>
#include "term_table/internal/cells_collection_t.hpp"
#include "term_table/i_canvas.hpp"
#include "term_table/grid_t.hpp"

namespace term_table::internal
{
    class table_data_t
    {
    public:
        using grid_ptr = std::shared_ptr<grid_t>;

        table_data_t(size_t rows_count,
                     size_t columns_count);

        size_t rows_count() const;

        size_t columns_count() const;

        cells_collection_t &cells();

        cells_collection_t const &cells() const;

        void draw(i_canvas &canvas) const;

    private:
        cells_collection_t cells_;
        grid_ptr grid_;
    };
}


