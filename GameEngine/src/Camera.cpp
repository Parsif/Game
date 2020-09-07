#include "camera.h"

namespace Engine
{
	Camera::Camera(const std::shared_ptr<sf::RenderWindow>& render_window) noexcept : render_window_(render_window)
	{
	}

	void Camera::move(const float offset_x, const float offset_y) const
	{
		auto view = render_window_->getView();
		view.move(offset_x, offset_y);
		render_window_->setView(view);
	}
}
