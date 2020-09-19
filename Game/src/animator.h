#pragma once
#include "pch.h"

#include <SFML/Graphics.hpp>

namespace Game
{
	class Animator
	{
	private:
		std::vector<sf::Sprite> sprites_;
		unsigned int current_sprite_number_ = 0;
		sf::Clock clock_;
		
		
	public:
		Animator(const std::vector <sf::Sprite> &sprites);
		[[nodiscard]] const sf::Sprite& get_next_sprite();
		void reset();
	};
}


