//
// Created by ukhegg on 02.10.22.
//

#pragma once

#include "term_table/i_visual.hpp"
#include "term_table/i_canvas_area.hpp"

#include <string>
#include <vector>

namespace term_table::visuals {
    class label_t : public i_visual {
    public:
        explicit label_t(std::string const& text);

        std::string text() const;

        size_t min_width() override;

        size_t min_height() override;

        size_t max_width() override;

        size_t max_height() override;

        size_t width() override;

        size_t height() override;

        void draw(i_canvas_area &canvas) override;
    private:
        std::vector<std::string> lines_;
    };
}


