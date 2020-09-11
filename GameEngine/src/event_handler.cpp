#include "pch.h"

#include "event_handler.h"

#include <imgui-SFML.h>




namespace Engine
{
	EventHandler::EventHandler(const std::shared_ptr<sf::RenderWindow>& render_window, const std::shared_ptr<CustomCursor>& custom_cursor, const std::shared_ptr<Grid>& grid, const Camera &camera)
								noexcept : render_window_(render_window), custom_cursor_(custom_cursor), grid_(grid), camera_(camera)
	{
        event_callbacks_[sf::Event::Closed] = [this]() { this->on_window_close(); };
        event_callbacks_[sf::Event::KeyPressed] = [this]() { this->on_key_pressed(); };
        event_callbacks_[sf::Event::MouseButtonPressed] = [this]() { this->on_mouse_click(); };
        event_callbacks_[sf::Event::Resized] = [this]() { this->on_window_resize(); };
        event_callbacks_[sf::Event::MouseWheelScrolled] = [this]() { this->on_mouse_scroll(); };

	}

	void EventHandler::on_event(const sf::Event &event)
	{
        current_event_ = event;
        ImGui::SFML::ProcessEvent(event);
        if (event_callbacks_.find(event.type) != event_callbacks_.end())
        {
            event_callbacks_[event.type]();
        }
	}


    void EventHandler::on_mouse_click()
    {
		// grid is a local copy instead of a reference to application grid
        if (custom_cursor_->is_sprite_attached())
        {
            grid_->on_mouse_click(custom_cursor_->get_attached_sprite());
        }

        custom_cursor_->detach_sprite();
    }

	void EventHandler::on_key_pressed() const
	{
        const int CELL_SIZE = grid_->get_cell_size();
        switch (current_event_.key.code)
        {
        case sf::Keyboard::Left:
            camera_.move(-(static_cast<float>(CELL_SIZE)), 0);
            grid_->on_camera_move();
            break;

        case sf::Keyboard::Right:
            camera_.move(CELL_SIZE,0);
            grid_->on_camera_move();
            break;

        case sf::Keyboard::Up:
            camera_.move(0, -(static_cast<float>(CELL_SIZE)));
            grid_->on_camera_move();
            break;

        case sf::Keyboard::Down:
            camera_.move(0, CELL_SIZE);
            grid_->on_camera_move();
            break;

        default:
            break;
        }
		
	}

	void EventHandler::on_window_close() const
	{
        render_window_->close();
	}

	void EventHandler::on_window_resize()
	{
        std::cout << "Resized" << '\n';
	}

	void EventHandler::on_mouse_scroll()
	{
        grid_->on_mouse_scroll(current_event_.mouseWheelScroll.delta);
	}
}
