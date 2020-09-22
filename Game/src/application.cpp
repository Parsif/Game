#include "pch.h"
#include "application.h"

#include <SFML/Window/Event.hpp>
#include "imgui-SFML.h"


namespace Game
{
	Application::Application()
	{
		map_ = std::make_shared<Map>(resource_manager_->get_cells());
		render_window_->setFramerateLimit(60);
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		sf::Clock delta_clock;
		while (render_window_->isOpen())
		{
			sf::Event event;
			while (render_window_->pollEvent(event))
			{
				event_handler_.on_event(event);
			}


			
			render_window_->clear();
			map_->draw(render_window_);
			player_->draw(render_window_);
			render_window_->display();
		}
	}
}

