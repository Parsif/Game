#pragma once

#include "resource_manager.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "map.h"
#include "event_handler.h"
#include "player.h"

namespace Game
{
	class Application
	{
	private:
		std::shared_ptr<sf::RenderWindow> render_window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(768, 512), "Game", sf::Style::Default);
		std::shared_ptr<ResourceManager> resource_manager_ = std::make_shared<ResourceManager>();
		std::shared_ptr<Map> map_;
		std::shared_ptr<Player>  player_ = std::make_shared<Player>(render_window_,
			resource_manager_->get_woodcutter_idle_sprites(), resource_manager_->get_woodcutter_run_sprites());
		EventHandler event_handler_{ render_window_, player_ };
		
	public:
		Application();
		~Application();
		Application(const Application& other) = delete;
		Application operator=(Application& other) = delete;
		Application(const Application&& other) = delete;
		Application operator=(Application&& other) = delete;
		
		void run();
	};
}


