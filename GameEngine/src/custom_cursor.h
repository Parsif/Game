#pragma once

#include "sprite_wrapper.h"

#include <SFML/Graphics.hpp>


namespace Engine
{
    class CustomCursor
    {
    private:
        SpriteWrapper attached_sprite_wrapper_;

    public:
        void draw(sf::RenderWindow &render_window) const;

        void attach_sprite(const SpriteWrapper &sprite_wrapper);
        void detach_sprite();
        [[nodiscard]] inline const auto& get_attached_sprite_wrapper() const noexcept { return attached_sprite_wrapper_; }
        [[nodiscard]] inline bool is_sprite_attached() const noexcept { return attached_sprite_wrapper_.get_sprite().getTexture() != nullptr; }
    };

}
