//
// Created by ukhegg on 03.10.22.
//

#pragma once

#include "term_table/i_visual.hpp"

namespace term_table::visuals {
    class horizontal_border_t : public i_visual {
    public:
        size_t min_width() override;

        size_t min_height() override;

        size_t width() override;

        size_t height() override;

        size_t max_width() override;

        size_t max_height() override;

        void draw(i_canvas_area &canvas) override;
    private:
        char symbol_{'-'};
    };
}


