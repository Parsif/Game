#pragma once
#include "pch.h"
#include "SFML/Graphics/RenderWindow.hpp"

namespace Engine
{
	class Camera
	{
	private:
		std::shared_ptr<sf::RenderWindow> render_window_;
	public:
		Camera(const std::shared_ptr<sf::RenderWindow>& render_window) noexcept;
		void move(const float offset_x, const float offset_y) const;
	};
}


