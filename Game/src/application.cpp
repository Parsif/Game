#include "pch.h"
#include "application.h"

#include <SFML/Window/Event.hpp>

namespace Game
{
	Application::Application()
	{
		map_ = std::make_shared<Map>(resource_manager_->get_cells());
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		
		while (render_window_->isOpen())
		{
			sf::Event event;
			while (render_window_->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					render_window_->close();
				}
			}
			render_window_->clear();
			map_->draw(render_window_);
			render_window_->display();
		}
	}
}

