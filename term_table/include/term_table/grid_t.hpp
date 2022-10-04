//
// Created by ukhegg on 23.10.2020.
//

#pragma once

#include "term_table/term_table_api.hpp"
#include "term_table/index_2d.hpp"
#include "term_table/keywords/table_keywords.hpp"
#include "term_table/i_visual.hpp"

#include <map>
#include <memory>
#include <string>
#include <vector>
#include <limits>

namespace term_table {
    class TERM_TABLE_API grid_t {
    public:
        using visual_ptr = std::shared_ptr<i_visual>;

        grid_t();

        grid_t(size_t rows_count, size_t columns_count);

        size_t rows_count() const;

        size_t columns_count() const;

        void set_column_min_width(column_index_t column, size_t width);

        void set_column_max_width(column_index_t column, size_t width);

        void set_row_min_height(row_index_t row, size_t height);

        void set_row_max_height(row_index_t row, size_t height);

        visual_ptr get_content(index_2d index);

        void set_content(index_2d index, visual_ptr visual);

        void set_text(index_2d index, std::string text);
    private:
        struct grid_cell_t {
            visual_ptr content;
        };

        struct column_info_t {
            size_t min_width{0};
            size_t max_width{std::numeric_limits<size_t>::max()};
        };

        struct row_info_t {
            size_t min_height{0};
            size_t max_height{std::numeric_limits<size_t>::max()};
        };

        size_t rows_count_{0};
        size_t columns_count_{0};
        std::map<index_2d, grid_cell_t> cells_;
        std::vector<row_info_t> rows_info_;
        std::vector<column_info_t> columns_info_;


        size_t row_min_height(row_index_t row) const;

        size_t column_min_width(column_index_t column) const;
    };
}
