//
// Created by ukhegg on 03.10.22.
//

#pragma once


#include "term_table/i_canvas.hpp"

namespace term_table
{
    class i_canvas_area : public i_canvas{
    public:
        virtual size_t width() = 0;

        virtual size_t height() = 0;
    };
}


