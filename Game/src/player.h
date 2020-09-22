#pragma once
#include "animator.h"

#include "global.h"

namespace Game
{
	class Player
	{
	private:
		std::shared_ptr<Animator> current_animator_;
		std::shared_ptr<Animator> idle_animator_;
		std::shared_ptr<Animator> run_animator_;
		int x_ = 0, y_ = 0;

	public:
		Player(const std::vector<sf::Sprite> &idle_sprites, const std::vector<sf::Sprite>& run_sprites);
	
		void draw(const std::shared_ptr<sf::RenderWindow> &render_window) const;

		void move(Direction direction);
		void idle();
	};
}


