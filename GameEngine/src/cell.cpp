#include "pch.h"

#include "cell.h"

namespace Engine
{
    Cell::Cell(int x, int y, unsigned int size) noexcept :  x_(x), y_(y), size_(size)
    {
    }

    void Cell::draw(const std::shared_ptr<sf::RenderWindow>& render_window, float scale_x, float scale_y)
    {
        if (attached_sprite.getTexture() != nullptr)
        {
            attached_sprite.setScale(scale_x, scale_y);
            attached_sprite.setPosition(x_, y_);
            render_window->draw(attached_sprite);
        }
    }

    void Cell::attach_sprite(const SpriteWrapper& sprite_wrapper)
    {
        sprite_wrapper_ = sprite_wrapper;
        attached_sprite = sprite_wrapper_.get_sprite();
    }

    void Cell::detach_sprite()
    {
        attached_sprite = sf::Sprite{};
        texture_filepath_ = "";
    }

    bool Cell::is_mouse_over(const std::shared_ptr<sf::RenderWindow> &render_window) const
    {
        const auto [mouse_pos_x, mouse_pos_y] = static_cast<sf::Vector2<int>>(render_window->mapPixelToCoords
                                                                   (sf::Mouse::getPosition(*render_window)));

        return mouse_pos_x >= x_ && mouse_pos_x <= x_ + static_cast<int>(size_) &&
               mouse_pos_y >= y_ && mouse_pos_y <= y_ + static_cast<int>(size_);
    }

    bool Cell::is_empty() const
    {
        return attached_sprite.getTexture() == nullptr;
    }

    void Cell::set_size(unsigned int size)
    {
        size_ = size;
    }
}


