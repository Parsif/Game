//
// Created by Vlad on 8/28/2020.
//

#include "pch.h"

#include "grid.h"

namespace Engine
{
    Grid::Grid(const std::shared_ptr<sf::RenderWindow> &render_window, unsigned int cell_size) : render_window_(render_window) ,cell_size_(cell_size) // NOLINT(modernize-pass-by-value)
    {
        const auto[window_width, window_height] = render_window_->getSize();
        leftmost_x_ = 0;
        rightmost_x_ = window_width;
        topmost_y_ = 0;
        bottommost_y_ = window_height;

        for (int i = 0; i < window_width / cell_size_; ++i)
        {
            for (int j = 0; j < window_height / cell_size_; ++j)
            {
                cells_.emplace_back(Cell(cell_size * i, cell_size * j, cell_size));
            }
        }
    }

    void Grid::split() const
    {
        const auto[window_width, window_height] = render_window_->getSize();
        const sf::Color blue_color(135, 206, 250);

        //drawing vertical lines
        for (int i = 0; i <= window_width / cell_size_; ++i)
        {
            const auto VERTEX_1_COORD = render_window_->mapPixelToCoords(sf::Vector2i(cell_size_ * i, 0));
            const auto VERTEX_2_COORD = render_window_->mapPixelToCoords(sf::Vector2i(cell_size_ * i, window_height));

            sf::Vertex horizontal_line[] =
            {
                sf::Vertex(VERTEX_1_COORD, blue_color),
                sf::Vertex(VERTEX_2_COORD, blue_color)
            };
            render_window_->draw(horizontal_line, 2, sf::Lines);
        }

        // drawing horizontal lines
        for (int i = 0; i <= window_height / cell_size_; ++i)
        {
            const auto VERTEX_1_COORD = render_window_->mapPixelToCoords(sf::Vector2i(0, cell_size_ * i));
            const auto VERTEX_2_COORD = render_window_->mapPixelToCoords(sf::Vector2i(window_width, cell_size_ * i));

            sf::Vertex horizontal_line[] =
            {
                sf::Vertex(VERTEX_1_COORD, blue_color),
                sf::Vertex(VERTEX_2_COORD, blue_color)
            };
            render_window_->draw(horizontal_line, 2, sf::Lines);
        }
    }

    void Grid::draw_cells()
    {
        for (auto &cell : cells_)
        {
            cell.draw(render_window_);
        }
    }

    void Grid::on_click(const sf::Sprite &selected_sprite)
    {
        for (auto &cell : cells_)
        {
            if (cell.is_mouse_over(render_window_))
            {
                cell.attach_sprite(selected_sprite);
                break;
            }
        }
    }

    void Grid::on_camera_move()
    {
        const auto [window_width, window_height] = render_window_->getSize();
        const auto [view_center_x, view_center_y] = render_window_->getView().getCenter();

        const float left_boundary = view_center_x - (window_width / 2.f);
        const float right_boundary = view_center_x + (window_width / 2.f);
        const float top_boundary = view_center_y - (window_height / 2.f);
        const float bottom_boundary = view_center_y + (window_height / 2.f);

        // TODO: Handle memory consumption

        if (leftmost_x_ > left_boundary || rightmost_x_  < right_boundary ||
            topmost_y_  > top_boundary  || bottommost_y_ < bottom_boundary)
        {
            for (int i = 0; i <= window_height / cell_size_; ++i)
            {
                const auto cell_y = top_boundary + cell_size_ * i;
                cells_.emplace_back(left_boundary, cell_y, cell_size_);
                cells_.emplace_back(right_boundary - cell_size_, cell_y, cell_size_);
            }
            for (int i = 1; i < window_width / cell_size_; ++i)
            {
                const auto cell_x = left_boundary + cell_size_ * i;
                cells_.emplace_back(cell_x, top_boundary, cell_size_);
                cells_.emplace_back(cell_x, bottom_boundary - cell_size_, cell_size_);
            }
            leftmost_x_ = left_boundary;
            rightmost_x_ = right_boundary;
            topmost_y_ = top_boundary;
            bottommost_y_ = bottom_boundary;
        }
    }

}

