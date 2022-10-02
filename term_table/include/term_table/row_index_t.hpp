//
// Created by Zeliukin Nick on 12.09.22.
//

#pragma once

#include "term_table/integer_index_t.hpp"

namespace term_table
{
    struct row_index_tag_t
    {
    };

    using row_index_t = integer_index_t<row_index_tag_t>;
}


