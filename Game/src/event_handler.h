#pragma once
#include "pch.h"

#include <functional>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

#include "player.h"


namespace Game
{
    class EventHandler
    {
    private:
        sf::Event current_event_{};
        std::shared_ptr<sf::RenderWindow> render_window_;
        std::map<sf::Event::EventType, std::function<void()>> event_callbacks_;

        std::shared_ptr<Player> player_;
    	
    private:
        void on_mouse_click() const;
        void on_key_pressed();
        void on_key_released();
        void on_window_close() const;
        void on_window_resize();
	

    public:
        EventHandler(const std::shared_ptr<sf::RenderWindow> &render_window, const std::shared_ptr<Player> &player) noexcept;
        EventHandler(const EventHandler &other) = delete;
        EventHandler operator=(const EventHandler& other) = delete;
        EventHandler(const EventHandler&& other) = delete;
        EventHandler operator=(const EventHandler&& other) = delete;
    	~EventHandler() = default;
    	
        void on_event(const sf::Event& event);
    };

   
}
