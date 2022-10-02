//
// Created by Zeliukin Nick on 13.09.22.
//

#pragma once


#include "term_table/keywords/table_keywords.hpp"
#include <memory>

namespace term_table::internal{
    class table_data_t;

    class table_builder_t
    {
    public:
        using table_data_ptr = std::shared_ptr<table_data_t>;

        table_data_ptr get_result();

        void set_param(keywords::rows_count rows_count);

        void set_param(keywords::columns_count columns_count);

        template<class TValue, class TTag>
        void set_param(keywords::internal::tagged_value_t<TValue, TTag> const &param)
        {
            //static_assert(false, "param with TTag not implemented");
        }

    private:
        size_t rows_count_{1};
        size_t columns_count_{1};
    };
}


