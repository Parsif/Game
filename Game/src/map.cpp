#include "pch.h"
#include "map.h"

namespace Game
{
	Map::Map(const std::vector<Cell>& cells) : cells_(cells)
	{
		
	}

	void Map::draw(const std::shared_ptr <sf::RenderWindow> &render_window)
	{
		for (auto& cell : cells_)
		{
			cell.draw(render_window, scale_x_, scale_y_);
		}
	}
}

