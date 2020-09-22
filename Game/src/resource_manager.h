#pragma once

#include "pch.h"

#include <SFML/Graphics.hpp>

#include "cell.h"

namespace Game
{
    class ResourceManager
    {
    private:
        std::array<sf::Texture, 10> tile_textures_;
        std::map<std::string, sf::Sprite> tile_sprites_;
    	
        std::array<sf::Texture, 4> woodcutter_idle_textures_;
        std::vector<sf::Sprite> woodcutter_idle_sprites_;

        std::array<sf::Texture, 6> woodcutter_run_textures_;
        std::vector<sf::Sprite> woodcutter_run_sprites_;

    private:
        void load_cell_tiles();

    public:
        ResourceManager();
    	
        [[nodiscard]] std::vector<Cell> get_cells();
        [[nodiscard]] inline const auto& get_woodcutter_idle_sprites() const { return woodcutter_idle_sprites_; }
        [[nodiscard]] inline const auto& get_woodcutter_run_sprites() const { return woodcutter_run_sprites_; }
        [[nodiscard]] inline const auto& get_tile_sprite(const std::string &texture_name) noexcept { return tile_sprites_[texture_name]; }
    };

}

