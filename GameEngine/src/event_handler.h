#pragma once
#include "pch.h"

#include <functional>
#include <SFML/Window/Event.hpp>


#include "camera.h"
#include "custom_cursor.h"
#include "grid.h"

namespace Engine
{
    class EventHandler
    {
    private:
        sf::Event current_event_;
        std::shared_ptr<sf::RenderWindow> render_window_;
        std::shared_ptr<CustomCursor> custom_cursor_;
        std::shared_ptr<Grid> grid_;
        Camera camera_;
        std::map<sf::Event::EventType, std::function<void()>> event_callbacks_;
    	
    private:
        void on_mouse_click() const;
        void on_key_pressed() const;
        void on_window_close() const;
        void on_window_resize();
        void on_mouse_scroll() const;
	

    public:
        EventHandler(const std::shared_ptr<sf::RenderWindow> &render_window, const std::shared_ptr<CustomCursor>& custom_cursor,
					 const std::shared_ptr<Grid>& grid, const Camera& camera) noexcept;
        EventHandler(const EventHandler &other) = delete;
        EventHandler operator=(const EventHandler& other) = delete;
        EventHandler(const EventHandler&& other) = delete;
        EventHandler operator=(const EventHandler&& other) = delete;
    	~EventHandler() = default;
    	
        void on_event(const sf::Event& event);
        static void handle_events(sf::RenderWindow &render_window, CustomCursor &custom_cursor, Grid &grid);
    };

   
}
