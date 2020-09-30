#include "camera.h"

namespace Game
{
	Camera::Camera(const std::shared_ptr<sf::RenderWindow>& render_window) : render_window_(render_window)
	{
		const auto [width, height] = render_window->getSize();
		const sf::View view(sf::Vector2f(width / 2, height / 2), sf::Vector2f(width, height));
		render_window->setView(view);
	}

	void Camera::move(Direction direction, const float kOffsetAmount) const
	{
		auto view = render_window_->getView();
		switch (direction)
		{
			case Direction::Up:
				view.move(0.f, -kOffsetAmount);
				break;
			case Direction::Down:
				view.move(0.f, kOffsetAmount);
				break;
			case Direction::Left:
				view.move(-kOffsetAmount, 0.f);
				break;
			case Direction::Right:
				view.move(kOffsetAmount, 0.f);
				break;
			case Direction::None:
				break;
		}
		render_window_->setView(view);
	}
}
