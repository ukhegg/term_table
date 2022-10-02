//
// Created by Zeliukin Nick on 12.09.22.
//

#pragma once

#include <string>

namespace term_table::internal
{
    class cell_data_t
    {
    public:
        const std::string &data() const;

        void set_data(std::string data);

    private:
        std::string data_;
    };
}

