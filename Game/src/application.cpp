#include "pch.h"
#include "application.h"

#include <SFML/Window/Event.hpp>

namespace Game
{
	Application::Application()
	{
		resource_manager_->load_cell_tiles();
		resource_manager_->load_json_cells();
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		
		while (render_window_->isOpen())
		{
			render_window_->clear();
			sf::Event event;
			while (render_window_->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					render_window_->close();
				}
			}
			render_window_->display();
		}
	}
}

