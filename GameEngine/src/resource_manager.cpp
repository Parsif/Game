#include "pch.h"

#include "resource_manager.h"


namespace Engine
{
    ResourceManager::ResourceManager()
    {
        // TODO: add loading error handling

        const std::string base_dir = "./res/";
        const std::array<std::string, 10> texture_paths = { "MapTiles/tile1.png" , "MapTiles/tile2.png", "MapTiles/tile3.png", "MapTiles/tile4.png",
																"MapTiles/tile5.png", "MapTiles/tile6.png", "MapTiles/tile7.png",
        														"MapTiles/tile8.png", "MapTiles/tile9.png", "MapTiles/tile10.png" };
      
    	

        for (unsigned int i = 0; i < texture_paths.size(); ++i)
        {
            tile_textures_[i].loadFromFile(base_dir + texture_paths[i]);
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
