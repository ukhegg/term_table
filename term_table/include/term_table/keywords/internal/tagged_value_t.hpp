//
// Created by Zeliukin Nick on 13.09.22.
//

#pragma once


namespace term_table::keywords::internal
{
    template<class TType, class TTag>
    struct tagged_value_t
    {
        struct value_producer_t
        {
            tagged_value_t operator=(TType const &val)
            {
                return tagged_value_t{val};
            }
        };

        TType value;

        static value_producer_t equals;
    };

    template<class TType, class TTag>
    typename tagged_value_t<TType, TTag>::value_producer_t tagged_value_t<TType, TTag>::equals;
}
