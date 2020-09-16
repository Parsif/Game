#include "cell.h"

namespace Game
{
	Cell::Cell(int x, int y, unsigned int size) noexcept
	{
	}

	void Cell::draw(const std::shared_ptr<sf::RenderWindow>& render_window, float scale_x, float scale_y)
	{
		sprite_.setScale(scale_x, scale_y);
		render_window->draw(sprite_);
	}

	
}
