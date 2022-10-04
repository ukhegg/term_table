//
// Created by Zeliukin Nick on 12.09.22.
//

#pragma once

#include "term_table/term_table_api.hpp"
#include "term_table/row_index_t.hpp"
#include "term_table/column_index_t.hpp"
#include "term_table/table_cell_t.hpp"
#include "term_table/keywords/table_keywords.hpp"
#include "term_table/internal/table_builder_t.hpp"
#include "term_table/i_visual.hpp"

namespace term_table
{
    namespace internal
    {
        class table_data_t;
    }

    class TERM_TABLE_API table_t : public i_visual
    {
    public:
        table_t();

        template<class ... TTags, class ... TValues>
        table_t(keywords::internal::tagged_value_t<TValues, TTags> &&...parameters)
        {
            internal::table_builder_t builder;
            std::apply([&builder](auto ... param) {
                ((builder.set_param(param)), ...);
            }, std::forward_as_tuple(parameters ...));
            this->data_ = builder.get_result();
        }

        table_cell_t get_cell(row_index_t r_index, column_index_t c_index) const;

        size_t rows_count() const;

        size_t columns_count() const;


        size_t min_width() override;

        size_t min_height() override;

        size_t width() override;

        size_t height() override;

        size_t max_width() override;

        size_t max_height() override;

        void draw(i_canvas_area &canvas) override;

    private:
        using table_data_ptr = std::shared_ptr<internal::table_data_t>;

        table_data_ptr data_;

        explicit table_t(table_data_ptr data);
    };
}


