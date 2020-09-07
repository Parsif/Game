//
// Created by Vlad on 8/28/2020.
//

#ifndef MAPEDITOR_GRID_H
#define MAPEDITOR_GRID_H

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
        std::vector<Cell> cells_;

        float leftmost_x_, rightmost_x_, topmost_y_, bottommost_y_;

    public:
        Grid(const std::shared_ptr<sf::RenderWindow> &render_window, unsigned int cell_size);

        void split() const;
        void draw_cells();
        void on_click(const sf::Sprite &selected_sprite);
        void on_camera_move();

        [[nodiscard]] inline unsigned int get_cell_size() const { return cell_size_;};
    };

}
#endif //MAPEDITOR_GRID_H
