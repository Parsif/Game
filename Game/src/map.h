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
		float scale_x_ = 1.f, scale_y_ = 1.f;

	public:
		Map(const std::vector<Cell> &cells);

		void draw(const std::shared_ptr <sf::RenderWindow>& render_window);
	};
}

