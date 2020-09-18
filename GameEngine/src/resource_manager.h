#pragma once

#include "pch.h"

#include <SFML/Graphics.hpp>

#include "sprite_wrapper.h"

namespace Engine
{
    class ResourceManager
    {
    private:
        std::array<sf::Texture, 10> tile_textures_;
        std::array<sf::Sprite, 10> tile_sprites;
        std::array<SpriteWrapper, 10> tile_sprite_wrappers_;

    public:
        ResourceManager();
        [[nodiscard]] inline const auto& get_sprite_wrappers() const noexcept { return tile_sprite_wrappers_; }
        [[nodiscard]] inline unsigned int get_tile_size() const noexcept { return tile_textures_[0].getSize().x; }
    };

}

