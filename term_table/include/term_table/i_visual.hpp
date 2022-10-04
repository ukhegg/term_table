//
// Created by ukhegg on 02.10.22.
//

#pragma once
#include "term_table/i_canvas_area.hpp"

namespace term_table {
    class i_visual {
    public:
        virtual ~i_visual() = default;

        virtual size_t min_width() = 0;

        virtual size_t min_height() = 0;

        virtual size_t width() = 0;

        virtual size_t height() = 0;

        virtual size_t max_width() = 0;

        virtual size_t max_height() = 0;

        virtual void draw(i_canvas_area& canvas) = 0;
    };
}
