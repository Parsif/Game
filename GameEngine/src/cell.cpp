//
// Created by Vlad on 8/28/2020.
//

#include "pch.h"
#include "cell.h"

namespace Engine
{
    Cell::Cell(int x, int y, unsigned int size, const sf::Sprite &sprite) noexcept : x_(x), y_(y), size_(size),
                                                                                     attached_sprite(sprite)
    {
    }

    void Cell::draw(std::shared_ptr<sf::RenderWindow> &renderWindow)
    {
        if (attached_sprite.getTexture() != nullptr)
        {
            attached_sprite.setPosition(x_, y_);
            renderWindow->draw(attached_sprite);
        }
    }

    void Cell::attach_sprite(const sf::Sprite &sprite)
    {
        attached_sprite = sprite;
    }

    void Cell::detach_sprite()
    {
        attached_sprite = sf::Sprite{};
    }

    bool Cell::is_mouse_over(const std::shared_ptr<sf::RenderWindow> &render_window) const
    {
        const auto [mouse_pos_x, mouse_pos_y] = static_cast<sf::Vector2<int>>(render_window->mapPixelToCoords
                                                                   (sf::Mouse::getPosition(*render_window)));

        return mouse_pos_x >= x_ && mouse_pos_x <= x_ + static_cast<int>(size_) &&
               mouse_pos_y >= y_ && mouse_pos_y <= y_ + static_cast<int>(size_);
    }
}


