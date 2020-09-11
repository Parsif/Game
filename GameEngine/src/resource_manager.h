#pragma once

#include "pch.h"

#include <SFML/Graphics.hpp>

namespace Engine
{
    class ResourceManager
    {
    private:
        std::array<sf::Texture, 10> tile_textures_;
        std::array<sf::Sprite, 10> tile_sprites;
    public:
        ResourceManager() noexcept;

    public:
        [[nodiscard]] inline const auto& get_sprites() const { return tile_sprites; };
        [[nodiscard]] inline unsigned int get_tile_size() const { return tile_textures_[0].getSize().x; };
    };

}

