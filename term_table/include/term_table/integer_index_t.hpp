//
// Created by Zeliukin Nick on 12.09.22.
//

#pragma once

#include <cstddef>

namespace term_table
{
    template<class TTag>
    class integer_index_t
    {
    public:
        integer_index_t() = default;

        integer_index_t(size_t value) : value_(value)
        {
        }

        integer_index_t operator+(int value) const
        {
            auto result = *this;
            result.value_ += value;
            return result;
        }

        integer_index_t operator-(int value) const
        {
            auto result = *this;
            result.value_ += value;
            return result;
        }

        bool operator==(const integer_index_t &rhs) const
        {
            return value_ == rhs.value_;
        }

        bool operator!=(const integer_index_t &rhs) const
        {
            return !(rhs == *this);
        }

        bool operator<(const integer_index_t &rhs) const
        {
            return value_ < rhs.value_;
        }

        bool operator>(const integer_index_t &rhs) const
        {
            return rhs < *this;
        }

        bool operator<=(const integer_index_t &rhs) const
        {
            return !(rhs < *this);
        }

        bool operator>=(const integer_index_t &rhs) const
        {
            return !(*this < rhs);
        }

        integer_index_t operator++()
        {
            this->value_++;
            return *this;
        }

        integer_index_t operator++(int)
        {
            auto result = *this;
            this->value_++;
            return result;
        }

        integer_index_t operator+=(int delta){
            this->value_ += delta;
            return *this;
        }

        size_t value() const
        {
            return value_;
        }

    private:
        size_t value_{0};
    };
}

