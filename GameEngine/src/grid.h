#pragma once
#include "pch.h"

#include <SFML/Graphics.hpp>
#include "cell.h"


namespace Engine
{
    class Grid
    {
    private:
        std::shared_ptr<sf::RenderWindow> render_window_;
        unsigned int cell_size_;
        float leftmost_x_, rightmost_x_, topmost_y_, bottommost_y_;
        std::vector<Cell> cells_;

    private:
        void set_cell_size(unsigned int cell_size);

    public:
        float cell_scale_x = 1.f, cell_scale_y = 1.f;

    public:
        Grid(const std::shared_ptr<sf::RenderWindow> &render_window, unsigned int cell_size);

        void split() const;
        void draw_cells();
        void on_mouse_click(const SpriteWrapper& selected_sprite_wrapper);
        void on_camera_move();
        void on_window_resize();
        void on_mouse_scroll(float scroll_delta);

        [[nodiscard]] inline auto get_cell_size() const { return cell_size_;}
    	// TODO: fix copying of cells
        [[nodiscard]] inline const auto get_cells() const
        {
            std::vector<Cell> texture_cells;
            for (const auto& cell : cells_)
            {
	            if (!cell.is_empty()) texture_cells.push_back(cell);
            }
	        return texture_cells;
        }

    };

}
