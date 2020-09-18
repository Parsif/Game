#include "cell.h"

namespace Game
{
	Cell::Cell(const sf::Sprite &sprite, int x, int y, unsigned int size) noexcept : sprite_(sprite), x_(x), y_(y)
	{
	}

	void Cell::draw(const std::shared_ptr<sf::RenderWindow>& render_window, float scale_x, float scale_y)
	{
		sprite_.setScale(scale_x, scale_y);
		sprite_.setPosition(x_, y_);
		render_window->draw(sprite_);
	}

	
}
