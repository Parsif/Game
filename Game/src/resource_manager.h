#pragma once

#include "pch.h"

#include <SFML/Graphics.hpp>

#include "cell.h"

namespace Game
{
    class ResourceManager
    {
    private:
        std::map<std::string, sf::Sprite> tile_sprites_;
        std::array<sf::Texture, 10> tile_textures_;

    private:
        void load_cell_tiles();

    public:
        ResourceManager();
    	
        [[nodiscard]] std::vector<Cell> get_cells();
        [[nodiscard]] inline const auto& get_tile_sprite(const std::string &texture_name) noexcept { return tile_sprites_[texture_name]; }
    };

}

