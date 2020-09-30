#include "pch.h"

#include "event_handler.h"
#include "global.h"


namespace Game
{
	EventHandler::EventHandler(const std::shared_ptr<sf::RenderWindow>& render_window, const std::shared_ptr<Player>& player) noexcept : render_window_(render_window), player_(player)
	{
        event_callbacks_[sf::Event::Closed] = [this]() { this->on_window_close(); };
        event_callbacks_[sf::Event::KeyPressed] = [this]() { this->on_key_pressed(); };
        event_callbacks_[sf::Event::KeyReleased] = [this]() { this->on_key_released(); };
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
		switch (current_event_.key.code)
		{
        case sf::Keyboard::Left:
            player_->set_move_direction(Direction::Left);
            break;

        case sf::Keyboard::Right:
            player_->set_move_direction(Direction::Right);
            break;

        case sf::Keyboard::Up:
            player_->set_move_direction(Direction::Up);
            break;

        case sf::Keyboard::Down:
            player_->set_move_direction(Direction::Down);
            break;

        default:
            break;
		}
	}

	void EventHandler::on_key_released() const
	{
        player_->set_move_direction(Direction::None);
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
