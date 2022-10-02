//
// Created by ukhegg on 23.10.2020.
//

#pragma once

#include "term_table/term_table_api.hpp"
#include "term_table/index_2d.hpp"
#include "term_table/keywords/table_keywords.hpp"

#include <map>
#include <memory>

namespace term_table
{
    class i_visual
    {
    public:
        virtual ~i_visual() = default;

        virtual size_t min_width() = 0;

        virtual size_t min_height() = 0;
    };

    class TERM_TABLE_API grid_t
    {
    public:
        using visual_ptr = std::shared_ptr<i_visual>;


        grid_t();

        grid_t(size_t rows_count, size_t columns_count);

        size_t rows_count() const;

        size_t columns_count() const;

        visual_ptr get_visual(index_2d index)
        {
            return this->cells_.at(index).visual;
        }

        void set_visual(index_2d index, visual_ptr visual)
        {
            this->cells_.at(index).visual = visual;
        }


    private:
        struct grid_cell_t
        {
            visual_ptr visual;
        };

        size_t rows_count_{0};
        size_t columns_count_{0};
        std::map<index_2d, grid_cell_t> cells_;
    };
}
