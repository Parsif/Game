#pragma once
#include "pch.h"

#include "cell.h"

namespace Game
{
	class Map
	{
	private:
		std::vector<Cell> cells_;
		unsigned int cell_size_;

	public:
		Map();

		void draw();
	};
}

