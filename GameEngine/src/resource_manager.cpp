//
// Created by Vlad on 8/28/2020.
//
#include "pch.h"

#include "resource_manager.h"


namespace Engine
{
    ResourceManager::ResourceManager() noexcept
    {
        // TODO: add loading error handling

        const std::string base_dir = "./res/tiles1/";

        tile_textures_[0].loadFromFile(base_dir + "tile1.png");
        tile_textures_[1].loadFromFile(base_dir + "tile2.png");
        tile_textures_[2].loadFromFile(base_dir + "tile3.png");
        tile_textures_[3].loadFromFile(base_dir + "tile4.png");
        tile_textures_[4].loadFromFile(base_dir + "tile5.png");
        tile_textures_[5].loadFromFile(base_dir + "tile6.png");
        tile_textures_[6].loadFromFile(base_dir + "tile7.png");
        tile_textures_[7].loadFromFile(base_dir + "tile9.png");
        tile_textures_[8].loadFromFile(base_dir + "tile9.png");
        tile_textures_[9].loadFromFile(base_dir + "tile10.png");

        tile_sprites[0].setTexture(tile_textures_[0]);
        tile_sprites[1].setTexture(tile_textures_[1]);
        tile_sprites[2].setTexture(tile_textures_[2]);
        tile_sprites[3].setTexture(tile_textures_[3]);
        tile_sprites[4].setTexture(tile_textures_[4]);
        tile_sprites[5].setTexture(tile_textures_[5]);
        tile_sprites[6].setTexture(tile_textures_[6]);
        tile_sprites[7].setTexture(tile_textures_[7]);
        tile_sprites[8].setTexture(tile_textures_[8]);
        tile_sprites[9].setTexture(tile_textures_[9]);
    }
}
