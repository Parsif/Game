#include "animator.h"

namespace Game
{
	Animator::Animator(const std::vector<sf::Sprite>& sprites) : sprites_(sprites)
	{
	}
	
	const sf::Sprite& Animator::get_next_sprite()
	{
		// std::cout << clock_.getElapsedTime().asMilliseconds() << '\n';
		if (clock_.getElapsedTime().asMilliseconds() < 500 / sprites_.size())
		{
			return sprites_[current_sprite_number_];
		}
		
		clock_.restart();
		if (current_sprite_number_ + 1 < sprites_.size())
		{
			++current_sprite_number_;
			return sprites_[current_sprite_number_ - 1];
		}
		current_sprite_number_ = 0;
		return sprites_[current_sprite_number_];
	}

	void Animator::reset()
	{
		current_sprite_number_ = 0;
	}


}
