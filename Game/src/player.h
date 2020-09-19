#pragma once
#include "animator.h"

namespace Game
{
	class Player
	{
	private:
		std::unique_ptr<Animator> idle_animator_;
		int x_ = 0, y_ = 0;

	public:
		Player(const std::vector<sf::Sprite> &idle_sprites);
		void draw(const std::shared_ptr<sf::RenderWindow> &render_window) const;
	};
}


