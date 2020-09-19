#include "pch.h"

#include "event_handler.h"



namespace Game
{
	EventHandler::EventHandler(const std::shared_ptr<sf::RenderWindow>& render_window) noexcept : render_window_(render_window)
	{
        event_callbacks_[sf::Event::Closed] = [this]() { this->on_window_close(); };
        event_callbacks_[sf::Event::KeyPressed] = [this]() { this->on_key_pressed(); };
        event_callbacks_[sf::Event::MouseButtonPressed] = [this]() { this->on_mouse_click(); };
        event_callbacks_[sf::Event::Resized] = [this]() { this->on_window_resize(); };
	}

	void EventHandler::on_event(const sf::Event &event)
	{
        current_event_ = event;
        if (event_callbacks_.find(event.type) != event_callbacks_.end())
        {
            event_callbacks_[event.type]();
        }
	}
	

    void EventHandler::on_mouse_click() const
    {
      
    }

	void EventHandler::on_key_pressed() const
	{
		
	}

	void EventHandler::on_window_close() const
	{
        render_window_->close();
	}

	void EventHandler::on_window_resize()
	{
        std::cout << "Resized" << '\n';
	}


}
