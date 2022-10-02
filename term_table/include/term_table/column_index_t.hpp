//
// Created by Zeliukin Nick on 12.09.22.
//

#pragma once

#include "term_table/integer_index_t.hpp"

namespace term_table
{
    struct column_index_tag_t
    {
    };


    using column_index_t = integer_index_t<column_index_tag_t>;
}


