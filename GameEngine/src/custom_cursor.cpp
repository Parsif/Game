#include "pch.h"

#include "custom_cursor.h"


namespace Engine
{
    void CustomCursor::draw(sf::RenderWindow &render_window)
    {
        if (attached_sprite_.getTexture() != nullptr)
        {
            const auto [mouse_pos_x, mouse_pos_y] = render_window.mapPixelToCoords(sf::Mouse::getPosition(render_window));
            attached_sprite_.setPosition(mouse_pos_x, mouse_pos_y);
            render_window.draw(attached_sprite_);
        }

    }

    void CustomCursor::attach_sprite(const sf::Sprite &sprite)
    {
        attached_sprite_ = sprite;
    }

    void CustomCursor::detach_sprite()
    {
        attached_sprite_ = sf::Sprite{};
    }

    const sf::Sprite &CustomCursor::get_attached_sprite() const
    {
        return attached_sprite_;
    }
}
