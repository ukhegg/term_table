//
// Created by ukhegg on 23.10.2020.
//

#pragma once

#include "term_table/term_table_api.hpp"


namespace term_table
{
	class TERM_TABLE_API grid
	{
	public:
		grid();
		static size_t height();
		static size_t width();
	};
}
