#pragma once
#include "pch.h"

#include "global.h"

#include <SFML/Graphics/RenderWindow.hpp>


namespace Game
{
	class Camera
	{
	private:
		std::shared_ptr<sf::RenderWindow> render_window_;
		
	public:
		Camera(const std::shared_ptr<sf::RenderWindow>& render_window);
		void move(Direction direction, const float kOffsetAmount) const;
	};
}


