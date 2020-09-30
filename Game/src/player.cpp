#include "player.h"

namespace Game
{
	Player::Player(const std::shared_ptr<sf::RenderWindow>& render_window, const std::vector<sf::Sprite>& idle_sprites,
		const std::vector<sf::Sprite>& run_sprites) : camera_(render_window)
	{
		const auto [width, height] = render_window->getSize();
		x_ = width / 2;
		y_ = height / 2;
		idle_animator_ = std::make_shared<Animator>(idle_sprites);
		run_animator_ = std::make_shared<Animator>(run_sprites);
		current_animator_ = idle_animator_;
	}

	void Player::draw(const std::shared_ptr<sf::RenderWindow> &render_window)
	{
		auto sprite = current_animator_->get_next_sprite();
		move();
		sprite.setPosition(x_, y_);
		render_window->draw(sprite);
	}

	void Player::set_move_direction(const Direction direction)
	{
		move_direction_ = direction;
	}

	void Player::move()
	{
		constexpr int kMoveAmount = 3;
		camera_.move(move_direction_, kMoveAmount);
		switch (move_direction_)
		{
		case Direction::Right:
			current_animator_ = run_animator_;
			x_ += kMoveAmount;
			break;
		case Direction::Left:
			current_animator_ = run_animator_;
			x_ -= kMoveAmount;
			break;
		case Direction::Down:
			current_animator_ = run_animator_;
			y_ += kMoveAmount;
			break;
		case Direction::Up:
			current_animator_ = run_animator_;
			y_ -= kMoveAmount;
			break;
		case Direction::None:
			current_animator_ = idle_animator_;
			break;
		}
	}
}
