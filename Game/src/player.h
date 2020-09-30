#pragma once
#include "animator.h"
#include "camera.h"
#include "global.h"

namespace Game
{
	class Player
	{
	private:
		std::shared_ptr<Animator> current_animator_;
		std::shared_ptr<Animator> idle_animator_;
		std::shared_ptr<Animator> run_animator_;
		Camera camera_;
		Direction move_direction_ = Direction::None;
		int x_ = 0, y_ = 0;
		
	private:
		void move();

	public:
		Player(const std::shared_ptr<sf::RenderWindow>& render_window, 
			const std::vector<sf::Sprite> &idle_sprites, const std::vector<sf::Sprite>& run_sprites);
	
		void draw(const std::shared_ptr<sf::RenderWindow> &render_window);
		void set_move_direction(Direction direction);
	};
}


