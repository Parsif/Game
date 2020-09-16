#pragma once

#include <SFML/Graphics.hpp>

#include "sprite_wrapper.h"

namespace Engine
{
    class Cell
    {
    private:
        SpriteWrapper sprite_wrapper_;
        sf::Sprite attached_sprite;
        int x_, y_;
        unsigned int size_;
        std::string texture_filepath_;

    public:
        Cell(int x, int y, unsigned int size) noexcept;

        void draw(const std::shared_ptr<sf::RenderWindow>& render_window, float scale_x, float scale_y);
        void attach_sprite(const SpriteWrapper& sprite_wrapper);
        void detach_sprite();
        bool is_mouse_over(const std::shared_ptr<sf::RenderWindow> &render_window) const;
        bool is_empty() const;
        void set_size(unsigned int size);

        [[nodiscard]] inline auto get_texture_filepath() const noexcept { return sprite_wrapper_.get_texture_filepath(); }
        [[nodiscard]] inline auto get_coord() const noexcept { return sf::Vector2<int>(x_, y_); }
    };
}
