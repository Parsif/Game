#pragma once

#include "pch.h"

#include <SFML/Graphics.hpp>

namespace Game
{
    class ResourceManager
    {
    private:
        std::array<sf::Texture, 10> tile_textures_;
        std::array<sf::Sprite, 10> tile_sprites;

    public:
        void load_cell_tiles();
        void load_json_cells();
        [[nodiscard]] inline const auto& get_sprites() const noexcept { return tile_sprites; }
        [[nodiscard]] inline unsigned int get_tile_size() const noexcept { return tile_textures_[0].getSize().x; }
    };

}

