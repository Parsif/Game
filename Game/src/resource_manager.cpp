#include "pch.h"

#include "resource_manager.h"

#include "cell.h"


namespace Game
{
    ResourceManager::ResourceManager()
    {
        load_cell_tiles();
    }
	
    void ResourceManager::load_cell_tiles()
    {
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
            const sf::Sprite sprite(tile_textures_[i]);
            tile_sprites_[texture_paths[i]] = sprite;
        }
    	
    }

    [[nodiscard]] std::vector<Cell> ResourceManager::get_cells() 
    {
        std::ifstream i("../grid.json");
        if (!i.is_open())
        {
            std::cerr << "Cannot open file" << '\n';
            return std::vector<Cell>();
        }
        nlohmann::json json;
        i >> json;

        std::vector <Cell> cells;
        for (const auto& json_cell : json)
        {
            const auto txt_path = json_cell["txt_path"].get<std::string>();
            const auto x = json_cell["x"].get<int>();
            const auto y = json_cell["y"].get<int>();
            cells.emplace_back(tile_sprites_[txt_path], x, y, tile_textures_[0].getSize().x);
        }
        return cells;
    }

    
}
