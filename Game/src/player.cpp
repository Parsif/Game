#include "player.h"

namespace Game
{
	Player::Player(const std::vector<sf::Sprite>& idle_sprites)
	{
		idle_animator_ = std::make_unique<Animator>(idle_sprites);
	}

	void Player::draw(const std::shared_ptr<sf::RenderWindow> &render_window) const
	{
		auto sprite = idle_animator_->get_next_sprite();
		sprite.setPosition(x_, y_);
		render_window->draw(sprite);
	}
}
