//
// Created by ukhegg on 02.10.22.
//

#include "term_table/visuals/label_t.hpp"
#include <algorithm>
#include <numeric>

namespace term_table::visuals {
    label_t::label_t(std::string const &text) {
        size_t prev_line_begin = 0;
        while (true) {
            auto new_line_pos = text.find('\n', prev_line_begin);
            if (new_line_pos == std::string::npos) {
                this->lines_.emplace_back(text.substr(prev_line_begin));
                break;
            }

            auto line_width = new_line_pos - prev_line_begin;
            this->lines_.emplace_back(text.substr(prev_line_begin, line_width));
            prev_line_begin = new_line_pos + 1;
        }
    }

    std::string label_t::text() const {
        std::string result;
        bool is_first = true;
        for (auto const &line: this->lines_) {
            if (is_first) is_first = false;
            else result += '\n';
            result += line;
        }
        return result;
    }

    size_t label_t::width() {
        return std::accumulate(begin(this->lines_), end(this->lines_),
                               size_t{0}, [](size_t prev, std::string const &line) {
                    return std::max(prev, line.size());
                });
    }

    size_t label_t::height() {
        return this->lines_.size();
    }

    void label_t::draw(i_canvas_area &canvas) {
        row_index_t row{0};
        for (auto const &line: this->lines_) {
            for (column_index_t column = 0; column < line.size(); ++column) {
                canvas.put(row, column, line.at(column.index()));
            }
            row++;
        }
    }

    size_t label_t::min_width() {
        return 0;
    }

    size_t label_t::min_height() {
        return 0;
    }

    size_t label_t::max_width() {
        return 0;
    }

    size_t label_t::max_height() {
        return 0;
    }


}