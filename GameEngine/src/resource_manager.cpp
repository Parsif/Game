#include "pch.h"

#include "resource_manager.h"


namespace Engine
{
    ResourceManager::ResourceManager()
    {
        // TODO: add loading error handling

        const std::string base_dir = "./res/tiles1/";
        const std::array<std::string, 10> texture_paths{ base_dir + "tile1.png",base_dir + "tile2.png",base_dir + "tile3.png",
                                                         base_dir + "tile4.png",base_dir + "tile5.png",base_dir + "tile6.png",
                                                         base_dir + "tile7.png",base_dir + "tile8.png",base_dir + "tile9.png",
                                                         base_dir + "tile10.png" };

        for (unsigned int i = 0; i < texture_paths.size(); ++i)
        {
            tile_textures_[i].loadFromFile(texture_paths[i]);
        }
        for (unsigned int i = 0; i < tile_textures_.size(); ++i)
        {
            tile_sprites[i].setTexture(tile_textures_[i]);
        }

        for (unsigned int i = 0; i < tile_sprites.size(); ++i)
        {
            tile_sprite_wrappers_[i] = SpriteWrapper(tile_sprites[i], texture_paths[i]);
        }
    }
}
