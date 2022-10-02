//
// Created by Zeliukin Nick on 13.09.22.
//

#pragma once
#include "term_table/keywords/internal/tagged_value_t.hpp"
#include <cstddef>

namespace term_table::keywords
{
    namespace internal
    {
        struct rows_count_tag_t
        {
        };
        struct columns_count_tag_t
        {
        };
    }

    using rows_count = internal::tagged_value_t<size_t, internal::rows_count_tag_t>;
    using columns_count = internal::tagged_value_t<size_t, internal::columns_count_tag_t>;
}