#include "player.h"

namespace Game
{
	Player::Player(const std::vector<sf::Sprite>& idle_sprites, const std::vector<sf::Sprite>& run_sprites)
	{
		idle_animator_ = std::make_shared<Animator>(idle_sprites);
		run_animator_ = std::make_shared<Animator>(run_sprites);
		current_animator_ = idle_animator_;
	}

	void Player::draw(const std::shared_ptr<sf::RenderWindow> &render_window) const
	{
		auto sprite = current_animator_->get_next_sprite();
		sprite.setPosition(x_, y_);
		sprite.scale(-1.f, 1.f);
		render_window->draw(sprite);
	}

	void Player::move(Direction direction)
	{
		current_animator_ = run_animator_;
		constexpr int kMoveAmount = 10;
		switch (direction)
		{
		case Direction::Right:
			x_ += kMoveAmount;
			break;
		case Direction::Left:
			x_ -= kMoveAmount;
			break;
		case Direction::Down:
			y_ += kMoveAmount;
			break;
		case Direction::Up:
			y_ -= kMoveAmount;
			break;
		}
	}

	void Player::idle()
	{
		current_animator_ = idle_animator_;
	}
}
