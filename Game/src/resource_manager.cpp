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
        const std::string base_dir = "./res/";
        const std::array<std::string, 10> tile_texture_paths = { "MapTiles/tile1.png" , "MapTiles/tile2.png", "MapTiles/tile3.png", "MapTiles/tile4.png",
                                                            "MapTiles/tile5.png", "MapTiles/tile6.png", "MapTiles/tile7.png",
                                                            "MapTiles/tile8.png", "MapTiles/tile9.png", "MapTiles/tile10.png" };

    	
        for (unsigned int i = 0; i < tile_texture_paths.size(); ++i)
        {
            tile_textures_[i].loadFromFile(base_dir + tile_texture_paths[i]);
            const sf::Sprite sprite(tile_textures_[i]);
            tile_sprites_[tile_texture_paths[i]] = sprite;
        }

        const std::array<std::string, 4> woodcutter_idle_texture_paths = {"Woodcutter/Idle/woodcutter_idle1.png","Woodcutter/Idle/woodcutter_idle2.png",
        															"Woodcutter/Idle/woodcutter_idle3.png" , "Woodcutter/Idle/woodcutter_idle4.png" };

        for (unsigned int i = 0; i < woodcutter_idle_texture_paths.size(); ++i)
        {
            woodcutter_idle_textures_[i].loadFromFile(base_dir + woodcutter_idle_texture_paths[i]);
            woodcutter_idle_sprites_.emplace_back(woodcutter_idle_textures_[i]);
        }

        const std::array<std::string, 6> woodcutter_run_texture_paths = { "Woodcutter/Run/woodcutter_run1.png","Woodcutter/Run/woodcutter_run2.png",
                                                                   "Woodcutter/Run/woodcutter_run3.png" , "Woodcutter/Run/woodcutter_run4.png",
        															"Woodcutter/Run/woodcutter_run5.png", "Woodcutter/Run/woodcutter_run6.png" };

        for (unsigned int i = 0; i < woodcutter_run_texture_paths.size(); ++i)
        {
            woodcutter_run_textures_[i].loadFromFile(base_dir + woodcutter_run_texture_paths[i]);
            woodcutter_run_sprites_.emplace_back(woodcutter_run_textures_[i]);
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
