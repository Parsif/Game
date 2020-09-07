//
// Created by Vlad on 8/28/2020.
//

#ifndef MAPEDITOR_RESOURCE_MANAGER_H
#define MAPEDITOR_RESOURCE_MANAGER_H

#include "pch.h"

#include <SFML/Graphics.hpp>

#include "cell.h"

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

#endif //MAPEDITOR_RESOURCE_MANAGER_H
