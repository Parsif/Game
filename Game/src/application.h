#pragma once

#include "resource_manager.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "map.h"

namespace Game
{
	class Application
	{
	private:
		std::shared_ptr<sf::RenderWindow> render_window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(768, 512), "Game", sf::Style::Default);
		std::shared_ptr<ResourceManager> resource_manager_ = std::make_shared<ResourceManager>();
		std::shared_ptr<Map> map_;
		
	public:
		Application();
		~Application();
		Application(const Application& other) = delete;
		Application operator=(Application& other) = delete;
		Application(const Application** other) = delete;
		Application operator=(Application&& other) = delete;
		
		void run();
	};
}


