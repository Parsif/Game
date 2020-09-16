#include "pch.h"

#include "custom_cursor.h"


namespace Engine
{
    void CustomCursor::draw(sf::RenderWindow &render_window) const
    {
        if (attached_sprite_wrapper_.get_sprite().getTexture() != nullptr)
        {
            const auto [mouse_pos_x, mouse_pos_y] = render_window.mapPixelToCoords(sf::Mouse::getPosition(render_window));
            auto attached_sprite = attached_sprite_wrapper_.get_sprite();
            attached_sprite.setPosition(mouse_pos_x, mouse_pos_y);
            render_window.draw(attached_sprite);
        }

    }

    void CustomCursor::attach_sprite(const SpriteWrapper& sprite_wrapper)
    {
        attached_sprite_wrapper_ = sprite_wrapper;
    }

    void CustomCursor::detach_sprite()
    {
        attached_sprite_wrapper_ = SpriteWrapper{};
    }

 
}
