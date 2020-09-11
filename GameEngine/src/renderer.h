#pragma once
#include "custom_cursor.h"
#include "grid.h"
#include "resource_manager.h"

namespace Engine
{
	class Renderer
	{
	private:
		std::shared_ptr<sf::RenderWindow> render_window_;
		std::shared_ptr<CustomCursor> custom_cursor_;
		std::shared_ptr<Grid> grid_;
		std::shared_ptr<ResourceManager> resource_manager_;
	private:
		void render_imgui();
		void render_other() const;
	public:
		Renderer(const std::shared_ptr<sf::RenderWindow>& render_window, const std::shared_ptr<CustomCursor>& custom_cursor,
			const std::shared_ptr<Grid>& grid, std::shared_ptr<ResourceManager> resource_manager);
		Renderer(const Renderer& other) = delete;
		Renderer operator=(const Renderer& other) = delete;
		Renderer(const Renderer&& other) = delete;
		Renderer operator=(const Renderer&& other) = delete;
		~Renderer() = default;
		
		void render();
	};
}


