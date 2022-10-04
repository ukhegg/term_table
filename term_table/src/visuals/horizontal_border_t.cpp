//
// Created by ukhegg on 03.10.22.
//

#include <limits>
#include "term_table/visuals/horizontal_border_t.hpp"

namespace term_table::visuals {
    size_t horizontal_border_t::min_width() {
        return 0;
    }

    size_t horizontal_border_t::min_height() {
        return 1;
    }

    size_t horizontal_border_t::width() {
        return 0;
    }

    size_t horizontal_border_t::height() {
        return 1;
    }

    size_t horizontal_border_t::max_width() {
        return std::numeric_limits<size_t>::max();
    }

    size_t horizontal_border_t::max_height() {
        return 1;
    }

    void horizontal_border_t::draw(i_canvas_area &canvas) {
        for (column_index_t column = 0; column < canvas.width(); ++column) {
            canvas.put(row_index_t{0}, column, this->symbol_);
        }
    }
}
