#pragma once

#include <SFML/Graphics.hpp>

namespace Game
{
	class Cell
	{
	private:
		sf::Sprite sprite_;
		int x_, y_;
		
	public:
		Cell(const sf::Sprite &sprite, int x, int y, unsigned int size) noexcept;
		void draw(const std::shared_ptr<sf::RenderWindow>& render_window, float scale_x, float scale_y);

	};
}


